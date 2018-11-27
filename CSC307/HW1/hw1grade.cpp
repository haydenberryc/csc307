// CSC 307 Fall 2018
// hw1grade.cpp
#include <iostream>    
#include <cstdlib>     
#include "bag_with_receipts.h"      // With value_type defined as a char
using namespace std;
using namespace main_savitch_3;

int main()
{
	float total = 0;

	bag_with_receipts b1, b2, b3;

	bool test0 = true;
	size_t i = 0;
	for (char c = ' '; c <= '>'; ++c)
	{
		if (i != b1.insert(c))
			test0 = false;
		++i;
	}
	if (test0)
		total += 0.5;

	b2 = b1;
	for (char c = ' '; c <= '>'; ++c)
	{
		if (i != b2.insert(c))
			test0 = false;
		++i;
	}
	if (test0)
		total += 0.25;
	
	if ((2 * b1.size()) != b2.size())
		test0 = false;
	if (test0)
		total += 0.25;
	
	b3 = b2;
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
	if (test1)
		total += 0.5;

	item = ' ';
	while (test1 && (i < b2size))
	{
		char item1 = 'a';
		char item2 = 'b';
		b1.remove(i, item1);
		b2.remove(i, item2);
		if (item2 != item)
			test1 = false;
		++i;
		++item;
	}
	if (test1)
		total += 0.25;

	bool test2 = true;
	if (b3.insert('1') != b2size)
		test2 = false;
	if (test2)
		total += 0.25;
	
	char item3 = ' ';
	b3.remove(1, item3);
	if (item3 != '!')
		test2 = false;
	b3.remove(17, item3);
	if (item3 != '1')
		test2 = false;
	if (test2)
		total += 0.25;

	if (b3.insert('1') != 1)
		test2 = false;
	if (test2)
		total += 0.25;

	cout << "HW1: your score is " << total << endl;
	return EXIT_SUCCESS;
}
