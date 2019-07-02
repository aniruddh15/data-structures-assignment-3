//Author: Aniruddh Kathiriya
//Assignment:3
#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
  typedef int value_type;
  typedef std::size_t size_type;
  static const size_type CAPACITY = 30;

  set();
// postcondition: empty set has been created
  
  void insert (const value_type& entry);
  // precondition: if entry is not in the set, set is not full
  // postcondition: entry is in the set
  //efficiency: O(n)

  void remove (const value_type& entry);
// postcondition: entry is not in the set
  //efficiency: O(n)

  size_type size() const;
// postcondition: number of elements in the set has been returned
  //efficiency: O(1)

  bool contains (const value_type& entry) const;
// postcondition: whether entry is in the set has been returned
  //efficiency: O(n)

  friend set set_union (const set& s1, const set& s2);
  //postcondition: union of s1 & s2 has been returned
    //efficiency: O(2n^2)

  friend set set_intersection (const set& s1, const set& s2);
  // postcondition: intersection of s1 & s2 has been returned
    //efficiency: O(n^3)

  friend set set_difference (const set& s1, const set& s2);
// postcondition: difference of s1 - s2 has been returned
  //efficiency: O(n^3)

  friend bool is_subset (const set& s1, const set& s2);
// postcondition: returned whether s1 is a subset of s2
  //efficiency: O(n^3)

  friend bool operator == (const set& s1, const set& s2);
  // postcondition: returned whether s1 & s2 are equal
    //efficiency: O(n)

  friend std::ostream& operator << (std::ostream& output, const set& s);
// postcondition: s has been displayed on output
  //efficiency: O(n)

private:
  size_type find (const value_type& entry) const;
  // returned location of entry in the set if entry is in the set - used otherwise
  value_type data[CAPACITY];
  size_type used;
};


#endif