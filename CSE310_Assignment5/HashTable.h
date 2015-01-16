/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LocationNode.h"
#include <cmath>
#include <climits>

class HashTable
{
public:
	HashTable();
	HashTable(int tableSize);
	~HashTable();
	int Insert(string zipCode, string city, string state, int attempt);
	int Search(string zipCode, int attempt);
	int getSize();
	bool isFull();
	LocationNode* getLocationArray();
	void print();

private:
	int generateKey(string zipCode);
	int DoubleHash(int key, int attempt);
	int Hash1(int key);
	int Hash2(int key);
	
	LocationNode* m_locationNodeArray;
	int m_hashTableSize;
	int m_nodeCount;
};

#endif
