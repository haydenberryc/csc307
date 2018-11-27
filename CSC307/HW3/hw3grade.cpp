// CSC 307 Fall 2018
// hw3grade.cpp

#include <iostream>
#include <ctime>
#include <random>
#include <array>
#include "node1.h"

using namespace main_savitch_5;
using namespace std;
int main()
{
	default_random_engine dre((unsigned int)time(0));	
	float total = 0;
	
	constexpr size_t LIST1_SIZE = 18;
	constexpr size_t LIST2_SIZE = 180;
	constexpr size_t LIST3_SIZE = 100;
	uniform_int_distribution<int> ucdist(32, 127);
	char c = ucdist(dre);
	array<char, LIST1_SIZE> list1_array = { c };
	node* list1_headptr = new node(c, NULL);
	for (unsigned int i = 1; i < LIST1_SIZE; ++i)
	{
		char c = ucdist(dre);
		list1_array[LIST1_SIZE-i] = c;
		list_insert(list1_headptr, c);
	}

	bool test1 = true;
	list_reverse(list1_headptr);
	if (list_length(list1_headptr) != LIST1_SIZE)
		test1 = false;
	if (test1)
	{
		node* current = list1_headptr;
		for (auto cur = list1_array.crbegin(), end = list1_array.crend(); cur!=end; ++cur)
		{
			if (*cur != current->data())
				test1 = false;
			current = current->link();
		}
	}
	if (test1)
		total += 0.8;

	c = ucdist(dre);
	array<char, LIST2_SIZE> list2_array = { c };
	node* list2_headptr = new node(c, NULL);
	for (unsigned int i = 1; i < LIST2_SIZE; ++i)
	{
		char c = ucdist(dre);
		list2_array[LIST2_SIZE - i] = c;
		list_insert(list2_headptr, c);
	}
	bool test2 = true;;
	array<int, 96> count;
	count.fill(0);
	char split_value = ucdist(dre);
	node* list2_less = NULL;
	node* list2_allothers = NULL;
	list_split(list2_headptr, split_value, list2_less, list2_allothers);
	node* lesscopy_headptr = NULL;
	node* lesscopy_tailptr = NULL;
	list_copy(list2_less, lesscopy_headptr, lesscopy_tailptr);
	node* otherscopy_headptr = NULL;
	node* otherscopy_tailptr = NULL;
	list_copy(list2_allothers, otherscopy_headptr, otherscopy_tailptr);
	unsigned int num_less = 0;
	unsigned int num_allothers = 0;

	for (char c : list2_array)
	{
		++count[int(c)-32];
		if (c < split_value)
			++num_less;
		else
			++num_allothers;
	}

	if (num_less != list_length(list2_less) || num_allothers != list_length(list2_allothers))
		test2 = false;
	
	char target = 32;
	for (auto c : count)
	{
		if (c != 0 && target < split_value)
		{
			int targetcount = 0;
			while (targetcount < c)
			{
				node* target_ptr = list_search(lesscopy_headptr, target);
				while (target_ptr != NULL)
				{
					target_ptr->set_data(lesscopy_headptr->data());
					target_ptr = target_ptr->link();
					target_ptr = list_search(target_ptr, target); 
					list_head_remove(lesscopy_headptr);
					++targetcount;
				}
			}
			if (targetcount != c)
				test2 = false;
		}
		if (c != 0 && target >= split_value)
		{
			int targetcount = 0;
			while (targetcount < c)
			{
				node* target_ptr = list_search(otherscopy_headptr, target);
				while (target_ptr != NULL)
				{
					target_ptr->set_data(otherscopy_headptr->data());
					target_ptr = target_ptr->link();
					target_ptr = list_search(target_ptr, target);
					list_head_remove(otherscopy_headptr);
					++targetcount;
				}
			}
			if (targetcount != c)
				test2 = false;
		}
		++target;
	}
	if (0 != list_length(lesscopy_headptr) || 0 != list_length(lesscopy_headptr))
		test2 = false;
	if (test2)
		total += 0.8;

	uniform_int_distribution<int> ucdist2(1000, 1095);
	int n = ucdist2(dre);
	array<int, LIST3_SIZE> list3_array = { n };
	node* list3_headptr = new node(n, NULL);
	for (unsigned int i = 1; i < LIST3_SIZE; ++i)
	{
		n = ucdist2(dre);
		list3_array[LIST3_SIZE - i] = n;
		list_insert(list3_headptr, n);
	}

	bool test3 = true;
	sort_list(list3_headptr);

	if (list_length(list3_headptr) != LIST3_SIZE)
		test3 = false;
	if (test3)
	{
		node* current = list3_headptr;
		while (current != NULL && current->link() != NULL)
		{
			if (current->data() > current->link()->data())
				test3 = false;
			current = current->link();
		}
	}
	node* list3copy_headptr = NULL;
	node* list3copy_tailptr = NULL;
	list_copy(list3_headptr, list3copy_headptr, list3copy_tailptr);
	for (auto n : list3_array)
	{
		if (list_search(list3copy_headptr, n) == NULL)
			test3 = false;
		else
		{
			node* target_ptr = list_search(list3copy_headptr, n);
			target_ptr->set_data(list3copy_headptr->data());
			list_head_remove(list3copy_headptr);
		}
	}
	if (0 != list_length(list3copy_headptr))
		test3 = false;
	if (test3)
		total += 0.9;
	
	cout << "HW3: your score is " << total << endl;
	return EXIT_SUCCESS;	
}