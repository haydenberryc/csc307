//CSC 307 Fall 2018
// File: bst.h
// adapted from https://www.cs.colorado.edu/~main/chapter10/bag6.h and
//              https://www.cs.colorado.edu/~main/chapter10/bag6.template to:
// "Write a function that takes a binary search tree as input and 
//  produces a linked list of the entries, with the entries sorted 
//  (smallest entries at the front of the list and largest entries at the back). 
//  Hint: use in-order traversal."

#ifndef BST_H 
#define BST_H
#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions
#include "node3.h"

namespace main_savitch_10
{
	template <class Item>
	class bst
	{
	public:
		bst() { root_ptr = NULL; }
		bst(const bst<Item>& source);
		~bst();
		void operator=(const bst<Item>& source);

		std::size_t size() const { return tree_size(root_ptr); }	
		binary_tree_node<Item>*& root() { return root_ptr; }
		const binary_tree_node<Item>* root() const { return root_ptr; }

		// For remove_max, remove, and insert pre/postconditions and function skeleton/definitions,
		// please see bst_remove_max, bst_remove, and insert functions, respectively, in 
		//  https://www.cs.colorado.edu/~main/chapter10/bag6.h and
		//  https://www.cs.colorado.edu/~main/chapter10/bag6.template 	
		void remove_max(binary_tree_node<Item>*& root_ptr, Item& removed);
		bool remove(binary_tree_node<Item>*& root_ptr, const Item& target);
		void insert(const Item& entry);
	private:
		binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree
	};

	// " a function that takes a binary search tree as input" whose root_ptr is r, "and 
	//  produces a linked list of the entries," whose head and tail pointers are head_ptr 
	//  and tail_ptr, respectively, "with the entries sorted (smallest entries at the front 
	//  of the list and largest entries at the back). Hint: use in-order traversal."
	template <class Item>
	void makelist(node<Item>*& head_ptr, node<Item>*& tail_ptr, binary_tree_node<Item>* r);
}

#include "bst.template" // Include the implementation.
#endif

