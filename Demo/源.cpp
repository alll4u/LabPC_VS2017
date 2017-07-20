#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	//vector<int> vec = { 1,-1,2,-5,-6,-7 };
	//transform(vec.begin(), vec.end(), vec.begin(),
	//	[](int i)->int {if (i < 0)return -i; else return i; });

	//for (auto e : vec)
	//	cout << e << endl;

	size_t v1 = 42;
	auto f = [&v1]{return ++v1; };
	v1 = 0;
	auto j = f();
	cout << j << endl;
	system("pause");
}