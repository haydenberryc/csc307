#include "node1.h"
#include <iostream>
namespace main_savitch_5{

	void list_reverse(node*& head_ptr){
		node* reversed_list = NULL;
		node* cursor = head_ptr;
		
		cursor = head_ptr;
		
		while(cursor != NULL) {
			list_head_insert(reversed_list, cursor->data());
			cursor = cursor->link();
		}
		
		list_clear(head_ptr);

		head_ptr = reversed_list;
		cursor = head_ptr;
		
		reversed_list = NULL;
		delete reversed_list;
	}

	void list_split(node* head_ptr, node::value_type splitting_value, node*& headptr_to_less_than_nodes, node*& headptr_to_all_other_nodes){
		node* cursor = head_ptr;
		while(cursor != NULL) {
			if(cursor->data() < splitting_value) {
				list_head_insert(headptr_to_less_than_nodes, cursor->data());
			}
			else { list_head_insert(headptr_to_all_other_nodes, cursor->data()); }
			cursor = cursor->link();
		}
	}

	void sort_list(node*& head_ptr){
		node* cursor = head_ptr;
		node* sorted_list = NULL;
		
		double maxval;
		std::size_t maxpos, position;

		while(head_ptr != NULL) {
			cursor = head_ptr;
			maxpos = 0;
			position = 0;
			maxval = 0.0;
			while(cursor != NULL){
				if(cursor->data() > maxval) { maxval = cursor->data(); maxpos = position; }
				cursor = cursor->link();
				position++;
			}
			if(maxpos == 0) list_head_remove(head_ptr);
			else list_remove(list_locate(head_ptr, maxpos));
			list_head_insert(sorted_list, maxval);
		}
		list_clear(head_ptr);
		head_ptr = sorted_list;
		cursor = head_ptr;
	}
}
