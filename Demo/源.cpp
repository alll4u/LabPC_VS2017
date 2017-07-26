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

class Employee {
public:
	Employee(string _name) :name(_name), id(++i){
		cout << name << "'s id is " << id << endl;
	}
	Employee(const Employee &t) :name(t.name), id(++i) {}
	int id;
	string name;
	void show() {
		cout << "name is "<< name << ", id is "<< id << endl;
	}
	Employee &operator=(const Employee &e);
private:
	static int i;
};
int Employee::i = 0;
Employee &Employee::operator=(const Employee &e) {
	name = e.name;
	return *this;
}
void main() {
	Employee Jony = Employee("jonyj");
	Employee tt = Employee("tt");
	Employee vava = tt;
	Employee xx(tt);
	xx.show();
	vava.show();
	tt.show();
	Jony.show();
	system("pause");
}

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

