// CSC 307 Fall 2018
// hw4grade.cpp
#include <iostream>    
#include <cstdlib>     
#include <array>
#include "bag_with_receipts.h"      
using namespace std;

int main()
{
	float total = 0;

	main_savitch_3::bag_with_receipts<char> b1, b2, b3;
	bool test0 = true;
	size_t i = 0;
	for (char c = ' '; c <= '>'; ++c)
	{
		if (i != b1.insert(c))
			test0 = false;
		++i;
	}

	b2 = b1;
	for (char c = ' '; c <= '>'; ++c)
	{
		if (i != b2.insert(c))
			test0 = false;
		++i;
	}

	if ((2 * b1.size()) != b2.size())
		test0 = false;

	b3 = b2;
	size_t b1size = b1.size();
	size_t b2size = b2.size();

	char item = ' ';
	i = 0;
	while (test0 && (i < b1size))
	{
		char item1 = 'a';
		char item2 = 'b';
		b1.remove(i, item1);
		b2.remove(i, item2);
		if ((item1 != item) || (item2 != item))
			test0 = false;
		++i;
		++item;
	}
	item = ' ';
	while (test0 && (i < b2size))
	{
		char item1 = 'a';
		char item2 = 'b';
		b1.remove(i, item1);
		b2.remove(i, item2);
		if (item2 != item)
			test0 = false;
		++i;
		++item;
	}
	if (test0)
		total += 0.6;
	if (b3.insert('1') != b2size)
		test0 = false;
	char item3 = ' ';
	b3.remove(1, item3);
	if (item3 != '!')
		test0 = false;
	b3.remove(17, item3);
	if (item3 != '1')
		test0 = false;
	if (b3.insert('1') != 1)
		test0 = false;
	if (test0)
		total += 0.6;

	bool test1 = true;
	main_savitch_3::bag_with_receipts<array<int, 3>> b4;
	for (i = 0; i < 100; ++i)
	{
		array<int, 3> a;
		a.fill(i + 1000);
		if (i != b4.insert(a))
			test1 = false;
	}
	if (b4.size() != 100)
		test1 = false;
	if (test1)
		total += 0.7;
	i = 4;
	while (test1 && (i < 100))
	{
		array<int, 3> item1, item2;
		item1.fill(i + 1000);
		if (!(b4.remove(i, item2)) || (item1 != item2))
			test1 = false;
		i *= 4;
	}
	array<int, 3> item4;
	item4.fill(300);
	if (b4.remove(4, item4))
		test1 = false;
	if (b4.insert(item4) != 4)
		test1 = false;
	b4.insert(item4);
	if (b4.insert(item4) != 64)
		test1 = false;
	if (test1)
		total += 0.6;
	cout << "HW4: your score is " << total << endl;

	return EXIT_SUCCESS;
}
