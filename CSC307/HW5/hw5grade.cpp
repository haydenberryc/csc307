// CSC 307 Fall 2018
// hw5grade.cpp

#include <iostream>
#include <ctime>
#include <random>
#include <bitset>
#include <vector>
#include <string>
#include "stack1.h"
#include "stack2.h"
using namespace std;

template<typename S, typename V> 
bool test_flip(S s, V v)
{
	bool result = (s.size() == v.size());
	for (auto i = v.cbegin(); i != v.cend() && result ; ++i)
	{
		result = ((*i) == s.top()) && result;
		s.pop();
	}
	return result;
}

template<typename S, typename V>
bool test_swap(S s1, S s2, V v1, V v2)
{
	bool result = (s1.size() == v2.size()) && (s2.size() == v1.size());
	for (auto i = v1.cbegin(); i != v1.cend() && result; ++i)
	{
		result = ((*i) == s2.top()) && result;
		s2.pop();
	}
	for (auto i = v2.cbegin(); i != v2.cend() && result; ++i)
	{
		result = ((*i) == s1.top()) && result;
		s1.pop();
	}
	return result;
}

int main()
{
	default_random_engine dre((unsigned int)time(0));
	vector<int> size = { 0, 1, 2, 30 };
	float total = 0;
	uniform_int_distribution<int> ucdist(0, 0xfffff);
	uniform_int_distribution<int> ucdist2(2, 29);
	uniform_int_distribution<int> ucdist3(31, 299);
	size[2] = ucdist2(dre);
	vector<main_savitch_7A::stack<string>> vs1(4, main_savitch_7A::stack<string>());
	vector<main_savitch_7A::stack<bitset<20>>> vs2(4, main_savitch_7A::stack<bitset<20>>());
	vector<vector<string>> vs3(4, vector<string>());
	vector<vector<bitset<20>>> vs4(4, vector<bitset<20>>());
	int vi = 0;
	for (auto s : size)
	{
		for (int i = 0; i < s; ++i)
		{
			unsigned int ui = ucdist(dre);
			bitset<20> bs = ui;
			string bstr = bs.to_string();
			vs1[vi].push(bstr);
			vs3[vi].push_back(bstr);
			vs2[vi].push(bs);
			vs4[vi].push_back(bs);
		}
		++vi;
	}
	bool test1 = true;
	for (int i = 0; i < 4 && test1 ; ++i)
	{
		vs1[i].flip();
		vs2[i].flip();
		if (!test_flip(vs1[i], vs3[i]) || !test_flip(vs2[i], vs4[i]))
			test1 = false;
	}
	if (test1)
		total += 0.6;

	bool test2 = true;
	vs1[0].swap(vs1[2]);
	vs2[0].swap(vs2[2]);
	if (!test_swap(vs1[0], vs1[2], vs3[0], vs3[2]) || !test_swap(vs2[0], vs2[2], vs4[0], vs4[2]))
		test2 = false;
	if (test2)
	{
		vs1[3].swap(vs1[1]);
		vs2[3].swap(vs2[1]);
		if (!test_swap(vs1[3], vs1[1], vs3[3], vs3[1]) || !test_swap(vs2[3], vs2[1], vs4[3], vs4[1]))
			test2 = false;
	}
	if (test2)
	{
		vs1[0].swap(vs1[1]);
		vs2[0].swap(vs2[1]);
		if (!test_swap(vs1[0], vs1[1], vs3[2], vs3[3]) || !test_swap(vs2[0], vs2[1], vs4[2], vs4[3]))
			test2 = false;
	}
	if (test2)
		total += 0.6;

	size[2] = ucdist2(dre);
	size[3] = ucdist3(dre);
	vector<main_savitch_7B::stack<string>> vsb1(4, main_savitch_7B::stack<string>());
	vector<main_savitch_7B::stack<bitset<20>>> vsb2(4, main_savitch_7B::stack<bitset<20>>());
	vector<vector<string>> vsb3(4, vector<string>());
	vector<vector<bitset<20>>> vsb4(4, vector<bitset<20>>());
	vi = 0;
	for (auto s : size)
	{
		for (int i = 0; i < s; ++i)
		{
			unsigned int ui = ucdist(dre);
			bitset<20> bs = ui;
			string bstr = bs.to_string();
			vsb1[vi].push(bstr);
			vsb3[vi].push_back(bstr);
			vsb2[vi].push(bs);
			vsb4[vi].push_back(bs);
		}
		++vi;
	}
	bool test3 = true;
	for (int i = 0; i < 4 && test3; ++i)
	{
		vsb1[i].flip();
		vsb2[i].flip();
		if (!test_flip(vsb1[i], vsb3[i]) || !test_flip(vsb2[i], vsb4[i]))
			test3 = false;
	}
	if (test3)
		total += 0.65;

	bool test4 = true;
	vsb1[0].swap(vsb1[2]);
	vsb2[0].swap(vsb2[2]);
	if (!test_swap(vsb1[0], vsb1[2], vsb3[0], vsb3[2]) || !test_swap(vsb2[0], vsb2[2], vsb4[0], vsb4[2]))
		test4 = false;
	if (test4)
	{
		vsb1[3].swap(vsb1[1]);
		vsb2[3].swap(vsb2[1]);
		if (!test_swap(vsb1[3], vsb1[1], vsb3[3], vsb3[1]) || !test_swap(vsb2[3], vsb2[1], vsb4[3], vsb4[1]))
			test4 = false;
	}
	if (test4)
	{
		vsb1[0].swap(vsb1[1]);
		vsb2[0].swap(vsb2[1]);
		if (!test_swap(vsb1[0], vsb1[1], vsb3[2], vsb3[3]) || !test_swap(vsb2[0], vsb2[1], vsb4[2], vsb4[3]))
			test4 = false;
	}
	if (test4)
		total += 0.65;
	cout << "HW5: your score is " << total << endl;
	return EXIT_SUCCESS;
}
