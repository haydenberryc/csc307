// CSC 307 Fall 2018
// hw7grade.cpp

#include <iostream>
#include <ctime>
#include <random>
#include <bitset>
#include <vector>
#include <string>
#include "bt_class_da.h"
using namespace std;

int main()
{
	default_random_engine dre((unsigned int)time(0));
	float total = 0;
	uniform_int_distribution<unsigned int> ucdist(0, 0xff);
	uniform_int_distribution<unsigned int> ucdist2(0, 600000);
	vector<bitset<8>> vs;
	bool test1 = true;
	main_savitch_chapter10DA::binary_tree<bitset<8>> bt1;
	bitset<8> bs = ucdist(dre);
	vs.push_back(bs);				
	bt1.create_first_node(bs);
	if ((bt1.size() != 1) || bt1.has_left_child() || bt1.has_right_child())
		test1 = false;
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.add_right(bs);
	if ((!test1) || (bt1.size() != 2) || bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test1 = false;
	bt1.shift_right();
	if ((!test1) || (bt1.size() != 2) || bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[1]))
		test1 = false;
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.add_left(bs);
	if ((!test1) || (bt1.size() != 3) || !bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[1]))
		test1 = false;
	bt1.shift_up();
	if ((!test1) || (bt1.size() != 3) || bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test1 = false;
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.add_left(bs);
	if ((!test1) || (bt1.size() != 4) || !bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test1 = false;
	bt1.shift_left();
	if ((!test1) || (bt1.size() != 4) || bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[3]))
		test1 = false;
	bt1.shift_to_root();
	if ((!test1) || (bt1.size() != 4) || !bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test1 = false;
	bt1.shift_right();
	bt1.shift_left();
	if ((!test1) || (bt1.size() != 4) || bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[2]))
		test1 = false;
	bt1.shift_to_root();
	if ((!test1) || (bt1.size() != 4) || !bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test1 = false;
	if (test1)
		total += 0.75;

	bool test2 = true;
	main_savitch_chapter10DA::binary_tree<bitset<8>> bt2(bt1);
	bt2.shift_to_root();
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.shift_left();
	bt1.change(bs);
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.add_right(bs);
	if ((bt2.size() != 4) || !bt2.has_left_child() || !bt2.has_right_child() || (bt2.retrieve() != vs[0]))
		test2 = false;
	if ((!test2) || (bt1.size() != 5) || bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[4]))
		test2 = false;
	bt1.shift_right();
	bs = ucdist(dre);
	vs.push_back(bs);
	bt1.add_left(bs);
	if ((!test2) || (bt1.size() != 6) || !bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[5]))
		test2 = false;
	bt1.shift_up();
	bt1.shift_up();
	bt1.shift_right();
	bt1.shift_left();
	if ((!test2) || (bt1.size() != 6) || bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[2]))
		test2 = false;
	if (test2)
		total += 0.75;

	bool test3 = true;
	bt1.shift_to_root();
	main_savitch_chapter10DA::binary_tree<bitset<8>> bt3(bt1);
	bt1 = bt2;
	bt2 = bt3;
	bt1.shift_to_root();
	bt2.shift_to_root();
	bt3.shift_to_root();
	if ((bt1.size() != 4) || !bt1.has_left_child() || !bt1.has_right_child() || (bt1.retrieve() != vs[0]))
		test3 = false;
	bt1.shift_left();
	if ((!test3) || (bt1.size() != 4) || bt1.has_left_child() || bt1.has_right_child() || (bt1.retrieve() != vs[3]))
		test3 = false;
	if ((!test3) || (bt3.size() != 6) || !bt3.has_left_child() || !bt3.has_right_child() || (bt3.retrieve() != vs[0]))
		test3 = false;
	bt2.shift_left();
	if ((!test3) || (bt2.size() != 6) || bt2.has_left_child() || !bt2.has_right_child() || (bt2.retrieve() != vs[4]))
		test3 = false;
	if (test3)
		total += 0.5;

	bool test4 = true;
	main_savitch_chapter10DA::binary_tree<string> bt4;
	vector<string> vs2;
	vector<char> vs3;
	string uis = to_string(ucdist2(dre));
	bt4.create_first_node(uis);
	vs2.push_back(uis);
	for (int i = 0; i < 9; ++i)
	{
		uis = to_string(ucdist2(dre));
		vs2.push_back(uis);
		if (uis < "300000")
		{
			vs3.push_back('L');
			bt4.add_left(uis);
			bt4.shift_left();
		}
		else
		{
			vs3.push_back('R');
			bt4.add_right(uis);
			bt4.shift_right();
		}
	}
	vs3.push_back('R');
	uis = to_string(ucdist2(dre));
	vs2.push_back(uis);
	bt4.add_right(uis);
	bt4.shift_to_root();
	if ((bt4.size() != 11) || (bt4.retrieve() != vs2[0]))
		test4 = false;
	for (unsigned int i = 0; i < vs3.size() && test4; ++i)
	{
		if (vs3[i] == 'L')
		{
			bt4.shift_left();
			if (bt4.retrieve() != vs2[i + 1])
				test4 = false;
		}
		else
		{
			bt4.shift_right();
			if (bt4.retrieve() != vs2[i + 1])
				test4 = false;
		}
	}
	for (int i = bt4.size()-2 ; i >= 0 && test4; --i)
	{
		bt4.shift_up();
		if (bt4.retrieve() != vs2[i])
			test4 = false;
	}
	if (test4)
		total += 0.5;
	
	cout << "HW7: your score is " << total << endl;
	return EXIT_SUCCESS;
}
