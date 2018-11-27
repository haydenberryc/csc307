// CSC 307 Fall 2018
// hw6grade.cpp

#include <iostream>
#include <ctime>
#include <random>
#include <bitset>
#include <vector>
#include <string>
#include "queue2circularLL.h"
using namespace std;

int main()
{
	default_random_engine dre((unsigned int)time(0));
	float total = 0;
	uniform_int_distribution<unsigned int> ucdist(0, 0xffffff);
	uniform_int_distribution<unsigned int> ucdist2(102, 1023);
	uniform_int_distribution<unsigned int> ucdist3(1, 101);
	vector<bitset<24>> v1;
	bool test1 = true;
	main_savitch_8CLL::queue<bitset<24>> q1;
	unsigned int ui = ucdist(dre);
	bitset<24> bs = ui;
	v1.push_back(bs);
	if (q1.size() != 0)
		test1 = false;
	q1.push(bs);
	if ((q1.size() != 1) || (q1.front() != bs))
		test1 = false;
	main_savitch_8CLL::queue<bitset<24>> q2(q1);
	if ((q2.size() != 1) || (q2.front() != bs))
		test1 = false;
	q2.pop();
	if ((q2.size() != 0) || (q1.size() != 1) || (q1.front() != bs))
		test1 = false;
	bs = ucdist(dre);
	q1.push(bs);
	main_savitch_8CLL::queue<bitset<24>> q4(q1);
	if ((q4.size() != 2) || (q1.size() != 2) || (q1.front() != v1[0])|| (q4.front() != v1[0]))
		test1 = false;
	if (test1)
		total += 0.7;
	
	bool test2 = true;
	q2.push(q1.front());
	if ((q2.size() != 1) || (q2.front() != v1[0]) || (q1.size() != 2) || (q1.front() != v1[0]))
		test2 = false;
	q1.pop();
	if ((q1.size() != 1) || (q1.front() != bs))
		test2 = false;
	q1.pop();
	q1.push(q2.front());
	q2.pop();
	if ((q2.size() != 0) || (q1.size() != 1) || (q1.front() != v1[0]))
		test2 = false;
	if (test2)
		total += 0.6;

	bool test3 = true;
	unsigned int ui2 = ucdist2(dre);
	for (unsigned int i = 0; i < ui2; ++i)
	{
		bs = ucdist(dre);
		q1.push(bs);
		v1.push_back(bs);
	}
	q2 = q1;
	if ((q2.front() != v1[0]) || (q2.size() != ui2+1) || (q1.front() != v1[0]) || (q1.size() != ++ui2))
		test3 = false;
	unsigned int ui3 = ucdist3(dre);
	for (unsigned int i = 0; i < ui3 && test3; ++i)
	{
		if ((q1.front() != v1[i]) || (q1.size() != ui2 - i))
			test3 = false;
		q1.pop();
	}
	if ((q2.front() != v1[0]) || (q2.size() != ui2) || (q1.front() != v1[ui3]) || (q1.size() != ui2-ui3))
		test3 = false;
	q1 = q2;
	if ((q2.front() != v1[0]) || (q2.size() != ui2) || (q1.front() != v1[0]) || (q1.size() != ui2))
		test3 = false;
	for (unsigned int i = 0; i < ui2 && test3; ++i)
	{
		if ((q1.front() != v1[i]) || (q1.size() != ui2 - i))
			test3 = false;
		q1.pop();
	}
	if ((q2.front() != v1[0]) || (q2.size() != ui2) || (q1.size() != 0))
		test3 = false;
	if (test3)
		total += 0.6;

	bool test4 = true;
	main_savitch_8CLL::queue<string> q3;
	ui3 = ucdist3(dre);
	unsigned int i1 = ui2-ui3;
	unsigned int i2 = i1 - 1;
	unsigned int i3 = i2;
	q3.push(v1[i1].to_string());
	q3.push(v1[i2].to_string());
	if ((q3.size() != 2) || (q3.front() != v1[i1].to_string()))
		test4 = false;
	q3.pop();
	if ((q3.size() != 1) || (q3.front() != v1[i2].to_string()))
		test4 = false;
	ui3 = ucdist3(dre);
	i1 = ui2 - ui3;
	i2 = i1 - 1;
	q3.push(v1[i1].to_string());
	q3.push(v1[i2].to_string());
	if ((q3.size() != 3) || (q3.front() != v1[i3].to_string()))
		test4 = false;
	q3.pop();
	q3.pop();
	i3 = i2;
	if ((q3.size() != 1) || (q3.front() != v1[i3].to_string()))
		test4 = false;
	q3.pop();
	ui3 = ucdist3(dre);
	i1 = ui2 - ui3;
	i2 = i1 - 1;
	q3.push(v1[i1].to_string());
	q3.push(v1[i2].to_string());
	if ((q3.size() != 2) || (q3.front() != v1[i1].to_string()))
		test4 = false;
	q3.pop();
	if ((q3.size() != 1) || (q3.front() != v1[i2].to_string()))
		test4 = false;
	if (test4)
		total += 0.6;
	cout << "HW6: your score is " << total << endl;
	return EXIT_SUCCESS;
}
