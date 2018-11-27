// CSC 307 Fall 2018
// hw8grade.cpp

#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <string>
#include <limits>
#include <iterator>
#include <algorithm>
#include "bst.h"

using namespace std;

string sc;

template <typename Item>
void concat(Item& i)
{
	sc += i;
}

int main()
{
	default_random_engine dre((unsigned int)time(0));
	vector<unsigned int> v = { 3,6,1,4,5,2,3,1,2,6,4,5,2,1,5,4,6,3,2,1,6,4,5,1,5,4,6,2,2,1,5,4,1,4,5,2,1,5,4,4,5,1 };
	float total = 0.0;
	uniform_int_distribution<int> ucdist(10000, numeric_limits<int>::max());
	uniform_int_distribution<int> ucdist2(15, 128);
	string sc2;

	bool test1 = true;
	int b = ucdist(dre);
	vector<string> vs;
	vs.push_back(to_string(b++));
	vs.push_back(to_string(b++));
	vs.push_back(to_string(b++));
	vs.push_back(to_string(b++));
	vs.push_back(to_string(b++));
	vs.push_back(to_string(b));
	main_savitch_10::bst<string> t1;
	unsigned int i = 0;
	t1.insert(vs[v[i++]-1]);
	t1.insert(vs[v[i++]-1]);
	t1.insert(vs[v[i++]-1]);
	t1.insert(vs[v[i++]-1]);
	t1.insert(vs[v[i++]-1]);
	t1.insert(vs[v[i++]-1]);
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::preorder(concat<string>, t1.root());
	if ((t1.size() != 6) || (sc != sc2))
		test1 = false;
	main_savitch_10::bst<string> t2(t1);
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::postorder(concat<string>, t2.root());
	if ((t2.size() != 6) || (sc != sc2))
		test1 = false;
	if (test1)
		total += 0.8;

	bool test2 = true;
	t1.remove(t1.root(), vs[2]);
	sc.clear();
	main_savitch_10::postorder(concat<string>, t2.root());
	if ((t1.size() != 5) || (t2.size() != 6) || (sc != sc2))
		test2 = false;
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::preorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::postorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	t1.remove(t1.root(), vs[5]);
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::preorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::postorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	t1.remove(t1.root(), vs[1]);
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::preorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	sc2.clear();
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc2 += vs[v[i++] - 1];
	sc.clear();
	main_savitch_10::postorder(concat<string>, t1.root());
	if ((sc != sc2))
		test2 = false;
	if (test2)
		total += 0.8;
	
	bool test3 = true;
	main_savitch_10::bst<int> t3;
	vector<int> vi(131, -1);
	size_t si = ucdist2(dre);
	for (size_t i = 0; i < si; ++i)
	{
		int a = ucdist(dre) % 131;
		if (vi[a] == -1)
			t3.insert(a);
		vi[a] = a;
	}
	auto newend = remove(vi.begin(), vi.end(), -1);
	vi.resize(distance(vi.begin(), newend));
	main_savitch_10::node<int>* h = NULL;
	main_savitch_10::node<int>* t = NULL;
	makelist(h, t, t3.root());
	main_savitch_10::node<int>* cur = h;
	for (auto iter = vi.begin(); iter != vi.end() && test3; ++iter)
	{
		test3 = ((*iter) == (cur->data()));
		cur = cur->link();
	}
	if (test3 && (cur != NULL))
		test3 = false;
	if (test3)
		total += 0.9;
	cout << "HW8: your score is " << total;
	cout << endl;
	return 0;
}