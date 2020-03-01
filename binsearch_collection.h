//----------------------------------------------------------------------
// Author:
// Course: CPSC 223, Spring 2020
// Assign: 5
// File:   binsearch_collection.h
//
// TODO: Description here
//----------------------------------------------------------------------

#ifndef BINSEARCH_COLLECTION_H
#define BINSEARCH_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"


template<typename K, typename V>
class BinSearchCollection : public Collection<K,V>
{
public:

  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collectiona
  void remove(const K& a_key);

  // find and return the value associated with the key
  bool find(const K& search_key, V& the_val) const;

  // find and return the values with keys >= to k1 and <= to k2 
  void find(const K& k1, const K& k2, std::vector<V>& vals) const;
  
  // return all of the keys in the collection 
  void keys(std::vector<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(std::vector<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  int size() const;

private:

  // helper function for binary search
  bool binsearch(const K& key, int& index) const;

  // vector storage
  std::vector<std::pair<K,V>> kv_list;

};


// TODO: Implement functions here ...

#endif
