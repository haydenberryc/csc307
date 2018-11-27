// CSC 307 Fall 2018
// hw10grade.cpp

#include <ctime>
#include <random>
#include <iostream>
#include <vector>
#include <string>
#include "table1d.h"
#include "table1q.h"
using namespace std;

struct rec1{
	int key;
	int value;
	rec1(int k = -1, int v = -1) : key(k), value(v) {}
};
struct rec2 {
	int key;
	string value;
	rec2(int k = -1, string v = "") : key(k), value(v) {}
};

int main()
{
	default_random_engine dre((unsigned int)time(0));
	uniform_int_distribution<int> ucdist1(5, 10);
	uniform_int_distribution<int> ucdist2(1, 24);
	vector<int> vi1 = { 6, 13, 20, 27, 34, 41, 3 };
	vector<unsigned int> vf1 = { 6, 3, 0, 2, 4, 1, 5 };
	vector<int> vi2 = { 20, 41, 27, 10, 34 };
	vector<int> vi3 = { 45, 85, 38, 21, 78, 42, 34 };
	vector<unsigned int> vf3 = { 5, 6, 7, 0, 1, 2, 3 };
	vector<int> vi4 = { 21, 40, 42, 34 };
	vector<rec1> vr1, vr3;
	float total = 0; 

	bool test1 = true;
	main_savitch_12A_DH::table<rec1, 7> table1;
	for (auto i : vi1)
	{
		vr1.push_back(rec1(i, i));
	}
	for (auto i : vr1)
	{
		table1.insert(i);
	}
	auto fiter = vf1.begin();
	for (auto iter = vi1.begin(); iter != vi1.end() && test1; ++iter)
	{
		bool found;
		size_t ti;
		table1.find_index(*iter, found, ti);
		if ((!found) || (ti != (*fiter)))
			test1 = false;
		++fiter;
	}
	if (test1)
		total += 0.5;
	table1.remove(6);
	table1.remove(13);
	table1.remove(3);
	table1.insert(rec1(10, 10));
	table1.insert(rec1(17, 17));
	if ((table1.size() != 6) || table1.is_present(3) || table1.is_present(6) || table1.is_present(13) || (!table1.is_vacant(5)))
		test1 = false;
	size_t fi = 0;
	for (auto iter = vi2.begin(); iter != vi2.end() && test1; ++iter)
	{
		bool found;
		size_t ti;
		table1.find_index(*iter, found, ti);
		if ((!found) || (ti != fi))
			test1 = false;
		++fi;
	}
	if (test1)
		total += 0.4;
	main_savitch_12A_DH::table<rec2, 811> table2;
	unsigned int ki = ucdist1(dre);
	unsigned int r = ucdist2(dre);
	unsigned int rkey = r + 811;
	table2.insert(rec2(rkey, to_string(rkey)));
	for (unsigned int i = 1; i < ki; ++i)
	{
		rkey = r+i*(r+1);
		table2.insert(rec2(rkey, to_string(rkey)));	
	}
	rkey = r + (ki++)*(r + 1);
	table2.insert(rec2(r, to_string(r)));
	if (table2.size() != ki)
		test1 = false;
	bool found;
	size_t ti;
	table2.find_index(r, found, ti);
	if ((!found) || (ti != rkey))
		test1 = false;
	if (test1)
		total += 0.35;

	bool test2 = true;
	main_savitch_12A_QH::table<rec1, 8> table3;
	for (auto i : vi3)
	{
		vr3.push_back(rec1(i, i));
	}
	for (auto i : vr3)
	{
		table3.insert(i);
	}
	fiter = vf3.begin();
	for (auto iter = vi3.begin(); iter != vi3.end() && test2; ++iter)
	{
		bool found;
		size_t ti;
		table3.find_index(*iter, found, ti);
		if ((!found) || (ti != (*fiter)))
			test2 = false;
		++fiter;
	}
	if (test2)
		total += 0.5;
	table3.remove(78);
	table3.insert(rec1(40, 40));
	if ((table3.size() != 7) || table3.is_present(78) || (!table3.is_vacant(4)))
		test2 = false;
	fi = 0;
	for (auto iter = vi4.begin(); iter != vi4.end() && test2; ++iter)
	{
		bool found;
		size_t ti;
		table3.find_index(*iter, found, ti);
		if ((!found) || (ti != fi))
			test2 = false;
		++fi;
	}
	if (test2)
		total += 0.4;

	main_savitch_12A_QH::table<rec2, 1024> table4;
	ki = ucdist1(dre);
	r = ucdist2(dre);
	rkey = r + 1024;
	table4.insert(rec2(rkey, to_string(rkey)));
	rkey = r;
	for (unsigned int i = 1; i < ki; ++i)
	{
		rkey += i;
		table4.insert(rec2(rkey, to_string(rkey)));
	}
	rkey += (ki++);
	table4.insert(rec2(r, to_string(r)));
	if (table4.size() != ki)
		test2 = false;	
	table4.find_index(r, found, ti);
	if ((!found) || (ti != rkey))
		test2 = false;
	if (test2)
		total += 0.35;
	cout << "HW10: your score is " << total;
	cout << endl;
	return 0;
}