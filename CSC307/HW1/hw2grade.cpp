// CSC 307 Fall 2018
// hw2grade.cpp
#include <iostream>    
#include <cstdlib>     
#include "bag_with_receipts2.h"      // With value_type defined as a char
using namespace std;
using namespace main_savitch_4;

int main()
{
	float total = 0;

	bag_with_receipts b1, b2;
	bool test0 = true;
	size_t i = 0;
	for (char c = ' '; c <= '('; ++c)
	{
		if (i != b1.insert(c))
			test0 = false;
		++i;
	}

	if (!test0) cout << "failed 1\n";
	
	b2 = b1;

	if ((b1.size() != b2.size()) || (b1.size() != i))
		test0 = false;

	if(!test0) cout << "failed 2\n";
	cout << "debug here\n";
	for (char c = ')'; c <= 'Z'; ++c)
	{
		cout << "i: " << i << endl;	
		if (i != b2.insert(c))
			test0 = false;
		++i;
	}

	if (!test0) cout << "failed 3\n";

	if ((b1.size() >= b2.size()) || (b2.size() != i))
		test0 = false;

	if (!test0) cout << "failed 4\n";

	if (test0)
		total += 0.75;
	
	bag_with_receipts b3(b2);
	if (b2.size() != b3.size())
		test0 = false;
	b3 = b1;
	if (b1.size() != b3.size())
		test0 = false;
	if (test0)
		total += 0.25;

	size_t b1size = b1.size();
	size_t b2size = b2.size();
	bool test1 = true;
	char item = ' ';
	i = 0;
	while (test1 && (i < b1size))
	{
		char item1 = 'a';
		char item2 = 'b';
		b1.remove(i, item1);
		b2.remove(i, item2);
		if ((item1 != item) || (item2 != item))
			test1 = false;
		++i;
		++item;
	}
	i = 0;
	while (test1 && (i < 5))
	{
		if (b3.insert(item) != (b1size + b1.insert(item)))
			test1 = false;
		++item;
		++i;
	}
	if (b3.size() <= b1.size())
		test1 = false;
	if (test1)
		total += 0.75;

	bool test2 = true;
	item = '1';
	i = 17;
	while (test2 && (i < b2size))
	{
		char item2 = 'b';
		b2.remove(i, item2);
		if (item2 != item)
			test2 = false;
		++i;
		++item;
	}
	if (test2)
		total += 0.25;

	bag_with_receipts b4(b2);
	if (b2.insert('a') != 0)
		test2 = false;
	if (b4.insert('a') != 0)
		test2 = false;
	if (test2)
		total += 0.25;

	char item3 = ' ';
	if (b1.remove(9, item3))
		test2 = false;
	b3.remove(1, item3);
	if (item3 != '!')
		test2 = false;
	if (b3.insert('1') != 1)
		test2 = false;
	if (b2.insert('1') != 1)
		test2 = false;
	if (test2)
		total += 0.25;

	cout << "HW2: your score is " << total << endl;
	
	return EXIT_SUCCESS;
}
