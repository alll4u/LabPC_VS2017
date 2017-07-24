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
using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery {
public:
	TextQuery(istream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;
	//std::map < std::string, std::shared_ptr<set<line_no>>> wm;
	map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(istream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		//更新file这个vector<string>
		file->push_back(text);
		int n = file->size() - 1;
		//每个string用istringstream的方式分解为单词
		istringstream line(text);
		string word;
		while (line >> word) {
			//单词不在wm中，返回line为空指针，lines为空，我们分配一个新的set，并调用reset更新lines引用的shared_ptr,使其指向新分配的set
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
};

QueryResult
TextQuery::query(const string &sought)const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream& os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) {};
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

void runQueries(istream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}

