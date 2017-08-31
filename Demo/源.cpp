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
#include<algorithm>
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
int removeElement(vector<int>& nums, int val) {
	int sum = 0;
	for (int i = 0; i<nums.size(); i++) {
		if (nums[i] == val)
			sum++;
	}
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end();)
	{
		if (*it == val) {
			sum++;
			it = nums.erase(it);
		}
		else
			it++;
	}
	return sum;

}
int climbStairs(int n) {
	if (n == 0 || n == 1)
		return 1;
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	for (int i = 2; i <= n; i++) {
		a.push_back(a[i-2]+a[i - 1]);

	}
	return  a[n];
}

int subarraySum(vector<int>& nums, int k) {
	int cum = 0; // cumulated sum
	map<int, int> rec; // prefix sum recorder
	int cnt = 0; // number of found subarray
	rec[0]++; // to take into account those subarrays that begin with index 0
	for (int i = 0; i<nums.size(); i++) {
		cum += nums[i];
		cnt += rec[cum - k];
		rec[cum]++;
	}
	return cnt;
}
int sqrt(int x);
void addCombination(vector<vector<int>> &result, vector<int> &local, vector<int> &nums, int begin, int target);
int addsum(vector<int>, int, int);
int xxx(vector<int> nums, int k);
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

	/*string s = "ddda";
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
	cout << "longest is " << longest << endl;*/
	/*string str = "-0012304";

	bool positive = true;
	int i = 0;
	int result = 0;
	if (str[0] == '-') {
		positive = false;
	}
	if (str[0] == '+' || str[0] == '-') {
		i++;
	}
	while (str[i]=='0')i++;
	cout << "i is :" << i << endl;
	for (; i<str.size(); i++) {
		result += (str[i] - '0')*pow(10,(str.size() - i -1));
	}
	cout << (positive ? result : -result) << endl;
	cout << "result:" << result << endl;*/

	/*int x = 2147483647;
	int bits = x / 10;
	int ret = 0;
	const int intmax = 2147483647;
	const int intmin = (-2147483647 - 1);
	for (; x / 10;) {
		if (ret > intmax / 10 || ret < intmin / 10)
			cout << "error" << endl;
		int digit = x % 10;
		x /= 10;
		ret = ret * 10 + digit;
	}
	if (ret > intmax / 10 || ret < intmin / 10)
		cout << "error" << endl;
	int digit = x % 10;
	ret = ret * 10 + digit;
	cout << "ret is " << ret << endl;*/

	//*************************************Maximum Subarray 
	/*vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<vector<int>> matrix(nums.size(), vector<int>(nums.size()));
	int max = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		matrix[i][i] = nums[i]; if (matrix[i][i] > max)max = matrix[i][i];
		for (int j = i+1; j < nums.size(); j++) {

			matrix[i][j] = nums[j]+matrix[i][j - 1];	
			if (matrix[i][j] > max)max = matrix[i][j];
		}
		
	}
	cout << max << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			cout << matrix[i][j] << " ";
		}
		
		cout << endl;
	}
	cout << "test" << endl;*/

	//***************************Maximum Subarray 
	/*vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int* dp = new int[100];
	dp[0] = nums[0];
	int max = dp[0];
	for (int i = 1; i < nums.size(); i++) {
		dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];
		if (dp[i] > max)max = dp[i];
	}
	cout << max << endl;*/

	//******************** Length of Last Word
	
	
	/*for (int i = test.size()-1; i >=0 ; i--) {
		if (isspace(test[i]) && i != test.size() - 1)
			cout << (test.size() - 1 - i) << endl;
	}*/
	

	//string s = "a";
	//int len = s.size();

	//while (len>0 && isspace(s[len - 1])) {
	//	len--;
	//	
	//}
	//if (len == 0) {
	//	cout << "error" << endl;
	//}
	//cout << "len:" << len << endl;
	///*for (int i = 0; i < len; i++) {
	//	cout << s[i] << endl;
	//}*/

	//for (int i = len-1; i >= 0; i--) {
	//	if (isspace(s[i]))
	//		cout << (len - 1 - i);
	//}
	//cout << len << endl;

	/*vector<int> nums = {1,1,1,2};
	sort(nums.begin(), nums.end());
	int target = 2;
	vector<vector<int>> result;
	vector<int> local;
	addCombination(result, local, nums, 0, target);*/

	/*vector<vector<int>> a = { {1,2,3},{4,5,6} };
	for (auto it = a.begin(); it != a.end(); it++) {
		for (auto it2 = *it->begin(); it2 != *it->end(); *it++) {
			cout << *it2 << " " << endl;
		}
		cout << endl;
	}*/
	
	/*vector<int> height = { 2,2,2,2 };
	
	int i = 0, j = height.size()-1;
	int maxVal = min(height[i], height[j]) * (j - i);
	while (i<j) {
		int minVal = min(height[i], height[j]);
		while (height[i] <= minVal && i<j)
			i++;
		while (height[j] <= minVal && i<j)
			j--;
		maxVal = max(maxVal, min(height[i],height[j])*(j-i));
	}

	cout << maxVal << endl;*/

	vector<int> nums = {3,1,2,7,7,7};
	int k = 4;
	////cout << addsum(nums, 0, nums.size());
	//if (addsum(nums, 0, nums.size()) % k == 0)
	//	cout << nums.size() << endl;
	//int l = nums.size();
	//for (int i = 0; i < l;i++) {
	//	for (int j = 0; j < i; j++) {
	//		int temp = addsum(nums, j, l - i);
	//		if (temp%k == 0)
	//			cout << (l - i  ) << endl;
	//	}
	//	
	//}
	
	cout << xxx(nums, k) << endl;

	system("pause");
}

int xxx(vector<int> nums, int k) {
	vector<int> sum;
	int temp=0;
	sum.push_back(0);
	for (int i = 0; i < nums.size(); i++) {
		temp += nums[i];
		sum.push_back(temp);
	}
	map<int, int> pool;
	pool[0] = 0;
	int max = 0;
	for (int i = 1; i < sum.size(); i++) {
		int remainder = sum[i] % k;
		
		auto it = pool.find(remainder);
		//找到
		if (it != pool.end()) {
			int pos = i - it->second;
			max = max > pos ? max : pos;
		}		
		else
			pool[remainder] = i;
	}
	return max;
}

int addsum(vector<int> a, int begin, int end) {
	int result = 0;
	for (int i = begin; i < end; i++) {
		result += a[i];
	}
	return result;
}
//vector<vector<int>> combinationSum2(vector<int> &num, int target) {
//	vector<vector<int>> result;
//	vector<int> local;
//	
//}
void addCombination(vector<vector<int>> &result, vector<int> &local, vector<int> &nums, int begin, int target) {
	if (target == 0) {
		result.push_back(local);
		return;
	}
	else {
		for (int i = begin; i < nums.size(); i++) {
			if (nums[i] > target)return;
			if (i>0&&(nums[i] == nums[i - 1])&&i>begin)continue;
			local.push_back(nums[i]);
			addCombination(result, local, nums, i + 1, target - nums[i]);
			local.pop_back();
		}
	}
}
int sqrt(int x) {
	if (x == 0)
		return 0;
	int left = 1;
	int right = 16;
	int mid = left+( right-left) / 2;
	while (1) {
		mid = left + (right - left) / 2;
		if (x/mid < mid) {
			right = mid-1;
		}
		else {
			if (x / (mid +1) < mid + 1) {
				return mid;
			}
			left = mid+1;
		}
	}
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

