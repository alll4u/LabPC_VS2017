#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<list>
#include<memory>
#include<map>
#include<set>
#include<sstream>
#include<istream>
#include<fstream>  
using namespace std;

class TreeNode {
public:
	TreeNode() :value(), left(nullptr), right(nullptr), count(0) {}
	TreeNode(const string &s, int c) :value(s), count(c), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &);
	~TreeNode();

	TreeNode &operator=(const TreeNode &);
public:
	TreeNode *left;
	TreeNode *right;

	string value;
	int count;
private:	
};

TreeNode::TreeNode(const TreeNode &t):value(t.value),count(t.count),left(nullptr),right(nullptr) {
	if (t.left)
		left = new TreeNode(*t.left);
	if (t.right)
		right = new TreeNode(*t.right);
}

TreeNode::~TreeNode() {
	if (left) {
		delete left;
	}
	if (right)
		delete right;
}

TreeNode &TreeNode::operator=(const TreeNode &t) {
	value = t.value;
	count = t.count;
	
	TreeNode *tmp = nullptr;
	if (t.left)
		tmp = new TreeNode(*t.left);
	delete left;
	left = tmp;

	if (t.right)
		tmp = new TreeNode(*t.right);
	delete right;
	right = tmp;
	
	return *this;
}

class BinStrTree {
public:
	BinStrTree(const TreeNode &t = TreeNode()) :root(new TreeNode(t)) {}
	BinStrTree(const BinStrTree &);
	
	BinStrTree &operator=(const BinStrTree &);
	~BinStrTree();

	TreeNode *root;
};
BinStrTree::BinStrTree(const BinStrTree &t) {
	root = new TreeNode(*t.root);
	//递归调用TreeNode的拷贝构造函数
}
BinStrTree &BinStrTree::operator=(const BinStrTree &t) {
	TreeNode *tmp = nullptr;
	if (t.root)
		tmp = new TreeNode(*t.root);
	delete root;
	root = tmp;
	return *this;
}
BinStrTree::~BinStrTree() {
	//递归调用destructor of ‘TreeNode’
	delete root;
}

void preorder(TreeNode &tn) {
	cout << tn.value << ":" << tn.count << endl;
	if (tn.left) {
		preorder(*tn.left);
	}
	if (tn.right) {
		preorder(*tn.right);
	}

}

void main() {
	//vector<string> vc = { "xiao","fei","ji","xx" };
	//for (auto i : vc) {
	//	 
	//}
	//BinStrTree bst2;
	//BinStrTree bst(TreeNode("fei",sizeof("fei")));
	//
	//bst.root->left = new TreeNode("2", 2);
	//bst.root->right = new TreeNode("3", 3);
	//bst.root->left->left = new TreeNode("4", 4);
	//bst.root->right->right = new TreeNode("7", 7);

	//preorder(*bst.root);

	string s = "ddda";
	int n = s.size();
	string longest;
	vector<vector<bool>> matrix(n, vector<bool>(n));
	for (auto it = matrix.begin(); it != matrix.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}

	for (int i = n-1; i >=0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j || (s[i] == s[j] && (j-i<2 || matrix[i + 1][j - 1]))) {
				matrix[i][j] = true;
				if (longest.size() < j - i + 1)
					longest = s.substr(i, j - i + 1);
			}
		}
	}
	cout << "longest is " << longest << endl;


	system("pause");
}

//class HasPtr {
//public:
//	HasPtr(const string &s = string()) :
//		ps(new string(s)), i(0), use(new size_t(1)) {}
//	HasPtr(const HasPtr &p) :
//		ps(new string()), i(p.i), use(p.use) {
//		++*use;
//	}
//	HasPtr& operator=(const HasPtr &);
//	~HasPtr();
//private:
//	string *ps;
//	int i;
//	size_t *use;
//};
//
//HasPtr& HasPtr::operator=(const HasPtr &rhs) {
//	++*rhs.use;
//	if (--*use == 0) {
//		delete ps;
//		delete use;
//	}
//	ps = rhs.ps;
//	i = rhs.i;
//	use = rhs.use;
//	return *this;
//}
//
//HasPtr::~HasPtr() {
//	if (--*use == 0) {
//		delete ps;
//		delete use;
//	}
//}


//class Employee {
	//public:
	//	Employee(string _name) :name(_name), id(++i){
	//		cout << name << "'s id is " << id << endl;
	//	}
	//	Employee(const Employee &t) :name(t.name), id(++i) {}
	//	int id;
	//	string name;
	//	void show() {
	//		cout << "name is "<< name << ", id is "<< id << endl;
	//	}
	//	Employee &operator=(const Employee &e);
	//private:
	//	static int i;
	//};
	//int Employee::i = 0;
	//Employee &Employee::operator=(const Employee &e) {
	//	name = e.name;
	//	return *this;
	//}

//#include <iostream>
//#include <vector>
//#include <list>
//
//struct X {
//	X() { ++i; j = i; std::cout << "默认构造函数X() " << j << std::endl; }
//	X(const X &) { ++i; j = i; std::cout << "复制构造函数X(const X &) " << j << std::endl; }
//	X &operator=(const X &) { std::cout << "拷贝赋值运算符operator= " << j << std::endl; }
//	~X() { std::cout << "析构函数~X() " << j << std::endl; }
//	static int i;
//	int j;
//};
//
//int X::i = 0;
//
//void f1(X x) {
//}
//
//void f2(X &x) {
//}
//
//X f3() {
//	return X();
//}
//
//X f5() {
//	X x;
//	return x;
//}
//
//X &f4(X &x) {
//	return x;
//}
//
//int main() {
//	std::cout << "\n----- X x1;\n";
//	X x1;
//	std::cout << "\n----- f1(x1);\n";
//	f1(x1);
//	std::cout << "\n----- f2(x1);\n";
//	f2(x1);
//	std::cout << "\n----- X x3 = f3();\n";
//	X x3 = f3();
//	std::cout << "\n----- f3();\n";
//	f3();
//	std::cout << "\n----- X x5 = f5();\n";
//	X x5 = f5();
//	std::cout << "\n----- f5();\n";
//	f5();
//	std::cout << "\n----- X x4 = f4(x1);\n";
//	X x4 = f4(x1);
//	std::cout << "\n----- f4(x1);\n";
//	f4(x1);
//	std::cout << "\n----- X *x2 = new X;\n";
//	X *x2 = new X;
//	std::cout << "\n----- std::vector<X> vx;\n";
//	std::vector<X> vx;
//	std::cout << "\n----- vx.push_back(x1);\n";
//	vx.push_back(x1);
//	std::cout << "\n----- vx.push_back(*x2);\n";
//	vx.push_back(*x2);  // The vector is reallocate here.
//	std::cout << "\n----- std::list<X> vl;\n";
//	std::list<X> vl;
//	std::cout << "\n----- vl.push_back(x1);\n";
//	vl.push_back(x1);
//	std::cout << "\n----- vl.push_back(*x2);\n";
//	vl.push_back(*x2);  // The list does not need reallocate.
//	std::cout << "\n----- delete x2;\n";
//	delete x2;
//	std::cout << "\n----- \n";
//	system("pause");
//	return 0;
//}



//class HasPtr {
//public:
//	HasPtr(const string &s = string()) :
//		ps(new string(s)), i(0) { }
//	HasPtr(const HasPtr &ori) :
//		ps(new string(*ori.ps)), i(ori.i) { }
//	const string &get() { return *ps; }
//	void set(const string &s) { *ps = s; }
//private:
//	string *ps;
//	int i;
//};

//using line_no = vector<string>::size_type;
//class QueryResult {
//	friend ostream& print(ostream&, const QueryResult&);
//public:
//	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
//		sought(s), lines(p), file(f) {};
//private:
//	string sought;
//	shared_ptr<set<line_no>> lines;
//	shared_ptr<vector<string>> file;
//};
//class TextQuery {
//public:
//	TextQuery(ifstream &);
//	QueryResult query(const string &) const;
//private:
//	shared_ptr<vector<string>> file;
//	//std::map < std::string, std::shared_ptr<set<line_no>>> wm;
//	map<string, shared_ptr<set<line_no>>> wm;
//};
//TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
//	string text;
//	while (getline(is, text)) {
//		//更新file这个vector<string>
//		file->push_back(text);
//		int n = file->size() - 1;
//		//每个string用istringstream的方式分解为单词
//		istringstream line(text);
//		string word;
//		while (line >> word) {
//			//单词不在wm中，返回line为空指针，lines为空，我们分配一个新的set，并调用reset更新lines引用的shared_ptr,使其指向新分配的set
//			auto &lines = wm[word];
//			if (!lines)
//				lines.reset(new set<line_no>);
//			lines->insert(n);
//		}
//	}
//};
//
//QueryResult
//TextQuery::query(const string &sought)const {
//	static shared_ptr<set<line_no>> nodata(new set<line_no>);
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//		return QueryResult(sought, nodata, file);
//	else
//		return QueryResult(sought, loc->second, file);
//}
//string make_plural(size_t ctr, const string &word, const string &ending) {
//	return (ctr > 1) ? word + ending : word;
//}
//ostream &print(ostream& os, const QueryResult &qr) {
//	os << qr.sought << " occurs " << qr.lines->size() << " "
//		<< make_plural(qr.lines->size(), "time", "s") << endl;
//	for (auto num : *qr.lines)
//		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
//	return os;
//}
//
//
//
//void runQueries(ifstream &infile) {
//	TextQuery tq(infile);
//	while (true) {
//		cout << "enter word to look for, or q to quit:";
//		string s;
//		if (!(cin >> s) || s == "q")break;
//		print(cout, tq.query(s)) << endl;
//	}
//}
//void main() {
//	ifstream in("pig.txt");
//	runQueries(in);
//	system("pause");
//}

