//CSC 307 Fall 2018
// Chapter 12 programming project 3 
// File: table1d.h
// adapted from Figure 12.4 on page 604 and uses the template prefix 
//  template <class RecordType, size_t TABLE_SIZE> as shown on page 621
//  to use "double hashing" 

#ifndef TABLE1D_H
#define TABLE1D_H
#include <cstdlib>    // Provides size_t
#include <cassert>
namespace main_savitch_12A_DH
{
    template <class RecordType, size_t TABLE_SIZE>
    class table
    {
    public:
        table();
        void insert(const RecordType& entry);
        void remove(int key);
        bool is_present(int key) const;
		bool is_vacant(std::size_t index) const;
        void find(int key, bool& found, RecordType& result) const;
        std::size_t size( ) const { return used; }
		void find_index(int key, bool& found, std::size_t& index) const;
    private:
        // MEMBER CONSTANTS -- These are used in the key field of special records.
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        // MEMBER VARIABLES
        RecordType data[TABLE_SIZE];
        std::size_t used;
        // HELPER FUNCTIONS
		std::size_t hash1(int key) const { return (key % TABLE_SIZE); }
		std::size_t hash2(int key) const { return (1 + (key % (TABLE_SIZE - 2))); }
		std::size_t next_index(std::size_t index, int key) const; 
        bool never_used(std::size_t index) const;    
    };
}
#include "table1d.template" // Include the implementation.
#endif
