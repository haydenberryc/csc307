#include "bag_with_receipts.h"
#include <iostream>
using namespace main_savitch_3;

bag_with_receipts::bag_with_receipts()
{
	for(size_t i = 0; i < CAPACITY;i++){
		data[i] = ' ';
		in_use[i] = false;
		used = 0;

	}
}


bool bag_with_receipts::remove(int receipt, value_type& itemRemoved)
{
	itemRemoved = data[receipt];
	data[receipt] = ' ';
	in_use[receipt] = false;
	used--;
	return false;
}

std::size_t bag_with_receipts::insert(const value_type& item){
	if (size() < CAPACITY) {
		size_t i = 0;
		while (in_use[i] == true) { i++; }
		data[i] = item;
		in_use[i] = true;
		used++;
		return i;
	} else {
	return 0;
	}	
}

std::ostream& operator<<(std::ostream& os, const bag_with_receipts& b){
	return os;
}
