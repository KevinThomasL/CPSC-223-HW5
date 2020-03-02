//----------------------------------------------------------------------
// Author: Kevin Lunden
// Course: CPSC 223, Spring 2020
// Assign: 5
// File:   binsearch_collection.h
//
// TODO: More practice with vectors. Practice using binary search.
//----------------------------------------------------------------------

#ifndef BINSEARCH_COLLECTION_H
#define BINSEARCH_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"
using namespace std;

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

template <typename K, typename V>
bool BinSearchCollection<K,V>::binsearch(const K& key, int& index) const
{
   pair<K,V> p;
   int bottom = 0;
   int top = kv_list.size()-1;
   int middle;

   while (bottom <= top)
   {
    middle = (top+bottom)/2;
    p = kv_list.at(middle);

    if (key == p.first)
    {
     index = middle;
     return true;
    }       
    else if (key > p.first)
     bottom = middle+1;
    else if (key < p.first)
     top = middle-1;
   }        
  
   if (kv_list.size() != 0)
    index = bottom;
   else
    index = 0;

   return false;
}

// add a new key-value pair into the collection
template <typename K, typename V>
void BinSearchCollection <K,V>::add(const K& a_key, const V& a_val)
{
 int index;
 pair<K,V> tmp;
 tmp.first = a_key;
 tmp.second = a_val;

 if (binsearch(a_key, index) == false)
  kv_list.insert(kv_list.begin()+index, tmp);
}

// remove a key-value pair from the collectiona
template <typename K, typename V>
void BinSearchCollection <K,V>::remove(const K& a_key)
{
 int index;
 if (binsearch(a_key, index) == true)
  kv_list.erase(kv_list.begin()+index);
}

// find and return the value associated with the key
template <typename K, typename V>
bool BinSearchCollection <K,V>::find(const K& search_key, V& the_val) const
{
 int index;
 pair<K,V> tmp;
 if (binsearch(search_key, index) == true)
 {
  tmp = kv_list.at(index);
  the_val = tmp.second;
  return true;
 }

 return false;
}

// find and return the values with keys >= to k1 and <= to k2 
template <typename K, typename V>
void BinSearchCollection <K,V>::find(const K& k1, const K& k2, std::vector<V>& vals) const
{
 int index;
 binsearch(k1, index);
 pair<K,V> tmp = kv_list[index];

 while (tmp.first <= k2 && index < kv_list.size()) 
 {
  vals.push_back(tmp.second);
  index++;
  if (index < kv_list.size())
   tmp = kv_list[index];
 }
}

// return all of the keys in the collection 
template <typename K, typename V>
void BinSearchCollection <K,V>::keys(std::vector<K>& all_keys) const
{
 if (kv_list.size() > 0)
 {
  for (pair<K,V> tmp : kv_list)
   all_keys.push_back(tmp.first);
 }
}

// return all of the keys in ascending (sorted) order
template <typename K, typename V>
void BinSearchCollection <K,V>::sort(std::vector<K>& all_keys_sorted) const
{
 this->keys(all_keys_sorted);
}

// return the number of key-value pairs in the collection
template <typename K, typename V>
int BinSearchCollection <K,V>::size() const
{
 return kv_list.size();
}

#endif
