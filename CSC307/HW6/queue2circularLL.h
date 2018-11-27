//CSC 307 Fall 2018 HW6
// File: queue2circularLL.h
// adapted from https://www.cs.colorado.edu/~main/chapter8/queue2.h to:
// "Redo the queue class using a circular linked list"

#ifndef MAIN_SAVITCH_QUEUE2CLL_H     // Prevent duplicate definition
#define MAIN_SAVITCH_QUEUE2CLL_H
#include <cstdlib>   // Provides std::size_t
#include "node2.h"   // Node template class

namespace main_savitch_8CLL
{
    template<class Item>
    class queue
    {
    public:
		queue();
		queue(const queue<Item>& source);
		~queue();
		
		void operator=(const queue<Item>& source);
        
		void pop();
		void push(const Item& entry);
		Item& front();
		size_t size() const { return count; }
		bool empty() const { return (count == 0); }
    private:
        main_savitch_6B::node<Item>* rear_ptr; //"points to the last node in the queue"
        size_t count;       // Total number of items in the queue
    };
}
#include "queue2circularLL.template" // Include the implementation
#endif
