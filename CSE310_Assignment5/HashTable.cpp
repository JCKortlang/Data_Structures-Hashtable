/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#include "HashTable.h"

HashTable::HashTable()
{
	;
}

HashTable::HashTable(int hashTableSize)
{
	m_hashTableSize = hashTableSize;
	m_locationNodeArray = new LocationNode[m_hashTableSize];
	m_nodeCount = 0;
}

HashTable::~HashTable()
{
	delete [] m_locationNodeArray;
}

LocationNode* HashTable::getLocationArray()
{
	return m_locationNodeArray;
}

int HashTable::getSize()
{
	return m_hashTableSize;
}

bool HashTable::isFull()
{
	return m_nodeCount == m_hashTableSize;
}

/*
	Uses double hashing to insert a locationNode based on the generated key value of its zip code.

	Analysis:	Overall the expected runtime of this algorithm is O(6*n), where n <= hashTableSize.
				If the doublehash function were to cause O(n) runtime, then it would need to  be refactored.
				Based on my tests, my doubleHash() function generates < 3 collissions on a single node
				and therefore I		believe it to be efficient.
*/
int HashTable::Insert(string zipCode, string city, string state, int attempt)
{
	int key = generateKey(zipCode);											//O(6)
	int index = DoubleHash(key, attempt);									//O(1)

	if (attempt == m_hashTableSize || isFull())								//O(1)
	{
		return -1;															//O(1)
	}
	else if (m_locationNodeArray[index].isEmpty())							//O(1)
	{
		m_locationNodeArray[index].getLocation()->setZipCode(zipCode);		//O(1)
		m_locationNodeArray[index].getLocation()->setCity(city);			//O(1)
		m_locationNodeArray[index].getLocation()->setState(state);			//O(1)
		m_nodeCount++;														//O(1)
		return index;														//O(1)
	}
	else
	{
		m_locationNodeArray[index].recordCollision();						//O(1)
		return Insert(zipCode, city, state, attempt + 1);					//O(n), n <= hashTableSize
	}
}

/*
	Searches for an item in the hashTable using the same methods from Insert().
	As such its runtime is =Insert() ~= O(3)
*/
int HashTable::Search(string zipCode, int attempt)
{
	int key = generateKey(zipCode);
	int index = DoubleHash(key, attempt);

	if (attempt == m_hashTableSize)
	{
		return -1;
	}
	else if (m_locationNodeArray[index].getLocation()->getZipCode().compare(zipCode) == 0)
	{
		return index;
	}
	else
	{
		return Search(zipCode,attempt + 1);
	}
}

/*
	Generates a integer key value from the parameter string.
*/
int HashTable::generateKey(string zipCode)								//Runtime: O(6)
{
	int length = zipCode.length();										//O(1)
	int key = 0;														//O(1)
	int characterValue;													//O(1)

	for (int i = 0; i < length && key < INT_MAX; i++)					//O(k), Assuming k = 6 because zip code length = 5 + 1 [fail check].
	{
		characterValue = zipCode[i]-47;									//O(5)
		key += characterValue * pow(38, i);								//O(5)
	}
	return key;															//O(1)
}

int HashTable::Hash1(int key)											//Runtime = Theta(1)
{
	return key % m_hashTableSize;										//O(1)
}

int HashTable::Hash2(int key)											//Runtime = Theta(1)
{
	int p = m_hashTableSize*.618;										//O(1)
	return 1 + (key % p);												//O(1)
}

int HashTable::DoubleHash(int key, int attempt)							//Runtime = Theta(1)
{
	return (Hash1(key) + attempt*Hash2(key)) % m_hashTableSize;			//O(1)
}

void HashTable::print()
{
	cout << "\nIndex\tZip Code\tCity\t\tState\t\tCollisionCount\n" << endl;

	for (int i = 0; i < m_hashTableSize; i++)
	{
		cout << i << "\t";
		m_locationNodeArray[i].print();
	}
};
