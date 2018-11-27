// CSC 307 Fall 2018
// FILE: bag_with_receipts2.h
// adapted from https://www.cs.colorado.edu/~main/chapter4/bag2.h
// 
// TYPEDEF and MEMBER CONSTANTS:
//   typedef ____ value_type
//     bag_with_receipts::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     bag_with_receipts::size_type is the data type of any variable that keeps track of how many items
//     are in a bag.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     bag_with_receipts::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the bag class:
//   bag_with_receipts(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS 
//
//   void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//	bool remove(int receipt, value_type& itemRemoved)
	/*	"when you want to remove an item,
	you must provide a copy of the receipt as a parameter to the remove function.
	The remove function removes the item whose receipt has been presented,
	and also returns a copy of that item through a reference parameter."	*/
//	Postcondition: If "the item whose receipt has been presented" was in the bag, 
//	then the item has been removed and a copy of that item is returned through 
//	the reference parameter itemRemoved; otherwise the bag is unchanged. 
//	A false return value indicates that nothing was removed; true indicates otherwise.
//
//   void insert(const value_type& item)
	/*	"Each time an item is added to a bag with receipts,
	the insert function returns a unique integer called the receipt."
	"When a new item is added, we will find the first spot that is currently unused
	and store the new item there. The receipt for the item is the index of the location
	where the new item is stored." */
//  Postcondition: A new copy of item has been added to the bag.
//
// CONSTANT MEMBER FUNCTIONS 
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with bag objects.

#ifndef MAIN_SAVITCH_BAGWRDA_H
#define MAIN_SAVITCH_BAGWRDA_H
#include <cstdlib>  
#include <iostream>
namespace main_savitch_4
{
	class bag_with_receipts
    { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef char value_type;
		typedef std::size_t size_type;
		static const size_type DEFAULT_CAPACITY = 10;
		// CONSTRUCTORS and DESTRUCTOR
		bag_with_receipts(std::size_t initial_capacity = DEFAULT_CAPACITY);
		bag_with_receipts(const bag_with_receipts& source);  
		~bag_with_receipts();

        // MEMBER FUNCTIONS
		void operator=(const bag_with_receipts& source);

		void reserve(size_type new_capacity);
		bool remove(int receipt, value_type& itemRemoved);
		std::size_t insert(const value_type& item);

		std::size_t size( ) const { return used; }

		// overloaded << operator 
		friend std::ostream& operator<<(std::ostream& os, const bag_with_receipts& b);

    private:
		value_type *data;     // Pointer to partially filled dynamic array
		bool* in_use;
		std::size_t used;       // How much of array is being used
		std::size_t capacity;   // Current capacity of the bag
    };
}
#endif
