//CSC 307 Fall 2018
// Chapter 12 programming project 4 
// File: table1q.h
// adapted from Figure 12.4 on page 604 and uses the template prefix 
//  template <class RecordType, size_t TABLE_SIZE> as shown on page 621
//  to use "quadratic hashing" 

#ifndef TABLE1Q_H
#define TABLE1Q_H
#include <cstdlib>    // Provides size_t
#include <cassert>

namespace main_savitch_12A_QH
{
    template <class RecordType, size_t TABLE_SIZE>
    class table
    {
    public:
        table();
        void insert(const RecordType& entry);
        void remove(int key);   
        bool is_present(int key);
		bool is_vacant(std::size_t index) const;
        void find(int key, bool& found, RecordType& result) const;
		void find_index(int key, bool& found, std::size_t& index);
        std::size_t size( ) const { return used; }
    private:
        // MEMBER CONSTANTS -- These are used in the key field of special records.
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        // MEMBER VARIABLES
        RecordType data[TABLE_SIZE];
        std::size_t used;
		std::size_t count;
        // HELPER FUNCTIONS
		std::size_t hash(int key) const { return (key % TABLE_SIZE); }
		std::size_t next_index(std::size_t index);  
        bool never_used(std::size_t index) const;       
    };
}
#include "table1q.template" // Include the implementation.
#endif
