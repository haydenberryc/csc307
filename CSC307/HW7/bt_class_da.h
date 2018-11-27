//CSC 307 Fall 2018 HW7
// File: bt_class_da.h.
// adapted from https://www.cs.colorado.edu/~main/chapter10/bt_class.h to:
// "Design and implement a class for binary trees, following the specification of 
//  Figure 10.14 on page 536. Your design should use a dynamic array to hold 
//  the data from the nodes in the same way that a complete binary tree is usually
//  represented. However, these binary trees do not need to be complete. Instead, 
//  you should have a second private member variable that is a dynamic array
//  of boolean values called is_present. The is_present array indicates which nodes 
//  actually exist in the tree. ..."

// FILE: bt_class.h
// TEMPLATE CLASS PROVIDED: binary_tree<Item> (a binary tree where each node has
//   an item) The template parameter, Item, is the data type of the items in the
//   tree's nodes. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, a copy constructor and an assignment
//   operator.
//
// NOTE: Each non-empty tree always has a "current node."  The location of
// the current node is controlled by three member functions: shift_up,
// shift_to_root, shift_left, and shift_right.
//

#ifndef BT_CLASS_H
#define BT_CLASS_H
#include <cstdlib>    
#include <cassert>

namespace main_savitch_chapter10DA
{
    template <class Item>
    class binary_tree
    {
    public:
		static const int NO_CURRENT_NODE = -1;

        binary_tree(std::size_t initial_capacity = DEFAULT_CAPACITY){
			capacity = initial_capacity;
			data = new Item[capacity];
			is_present = new bool[capacity];
			for (std::size_t i = 0; i < capacity; ++i)
				is_present[i] = false;
			num_nodes = 0;
			current_node = NO_CURRENT_NODE; // " Each non-empty tree always has a "current node." "  
		};

        binary_tree(const binary_tree<Item>& source);
        ~binary_tree();
		void operator=(const binary_tree<Item>& source);
        
		// MODIFICATION MEMBER FUNCTIONS
        void create_first_node(const Item& entry);
        void shift_to_root( );
        void shift_up( );
        void shift_left( );
        void shift_right( );
        void change(const Item& new_entry);
        void add_left(const Item& entry);
        void add_right(const Item& entry);

        // CONSTANT MEMBER FUNCTIONS
		std::size_t size() const {
			return num_nodes;
		};
        Item retrieve() const;
        bool has_parent() const;
        bool has_left_child() const;
        bool has_right_child() const;  

    private:
		static const std::size_t DEFAULT_CAPACITY = 7;
		Item* data;			// "a dynamic array to hold the data from the nodes"
		bool* is_present;	// "indicates which nodes actually exist in the tree"
		std::size_t num_nodes;	// "the number of nodes in the tree"
		std::size_t capacity;   // current capacity of the parallel arrays: data and is_present
		int current_node;	// "Each non-empty tree always has a current node. 
							//  The location of the current node is controlled by:
							//  shift_up, shift_to_root, shift_left, and shift_right."	
		void reserve(std::size_t new_capacity);	// to increase the current capacity of 
												// the parallel arrays to new_capacity
												// "to hold the data from the nodes in 
												// the same way that a complete binary tree 
												// is usually represented."
    };
}
#include "bt_class_da.template" 
#endif 
