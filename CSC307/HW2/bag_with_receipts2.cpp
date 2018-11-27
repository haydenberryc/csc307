#include "bag_with_receipts2.h"
using namespace main_savitch_4;

bag_with_receipts::bag_with_receipts(std::size_t initial_capacity) {
	capacity = initial_capacity;
	used = 0;
	
	data = new value_type[capacity];
	in_use = new bool[capacity];

	for (std::size_t index = 0; index < capacity; index++) {
		data[index] = '\0';
		in_use[index] = false;
	}
}

bag_with_receipts::bag_with_receipts(const bag_with_receipts& source) {
	capacity = source.capacity;
	used = source.used;
	data = new value_type[capacity];
	in_use = new bool[capacity];
	
	for (std::size_t index = 0; index < capacity; index++) {
		data[index] = source.data[index];
		in_use[index] = source.in_use[index];
	}
}

bag_with_receipts::~bag_with_receipts() {
	delete[] data;
	delete[] in_use;
}

std::size_t bag_with_receipts::insert(const value_type& item) {
	if (size() == capacity-1) { reserve(used+10); }
	std::size_t receipt = 0;
	
	while (in_use[receipt] == true) { receipt++; }
	data[receipt] = item;
	in_use[receipt] = true;
	used++;
	return receipt;	
}

void bag_with_receipts::reserve(size_type new_capacity) {
	if (new_capacity == used) { new_capacity = used + 10; }
	
	value_type* tmpdata = new value_type[new_capacity];
	bool* tmpuse = new bool[new_capacity];

	for (std::size_t index = 0; index < capacity; index++) {
		tmpdata[index] = data[index];
		tmpuse[index] = in_use[index];
	}
	
	//delete[] data;
	//delete[] in_use;
	data = NULL;
	in_use = NULL;
	data = new value_type[new_capacity];
	in_use = new bool[new_capacity];

	for (std::size_t index = 0; index < capacity; index++) {
		data[index] = tmpdata[index];
		in_use[index] = tmpuse[index];
	}
	delete[] tmpdata;
	delete[] tmpuse;
	capacity = new_capacity;
}

bool bag_with_receipts::remove(int receipt, value_type& itemRemoved) {
	if (in_use[receipt] == true) {
		itemRemoved = data[receipt];
		data[receipt] = '\0';
		in_use[receipt] = false;
		used--;
		return true;
	}
	else { return false; }
}

void bag_with_receipts::operator=(const bag_with_receipts& source) {
	if (this == &source) { return; }
	capacity = source.capacity;
	used = source.used;

	value_type* tmpdata = new value_type[capacity];
	bool* tmpuse = new bool[capacity];
	
	for (std::size_t index = 0; index < capacity; index++) {
		tmpdata[index] = source.data[index];
		tmpuse[index] = source.in_use[index];	
	}
	
	delete[] data;
	delete[] in_use;

	data = new value_type[capacity];
	in_use = new bool[capacity];

	for (std::size_t index = 0; index < capacity; index++) {
		data[index] = tmpdata[index];
		in_use[index] = tmpuse[index];
	}
}	
