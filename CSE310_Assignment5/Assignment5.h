/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#ifndef ASSIGNMENT5_H
#define ASSIGNMENT5_H

#include "HashTable.h"

using std::getline;

//Object variables
HashTable* m_hashTable;

//Elemntary Variables
int m_hashTableSize;
string m_input;
string m_zipCode;
string m_city;
string m_state;
const string m_delimeter = ",";
string m_temp;

//Functions
string extractToken(string* input);
void sizePrompt();
void insertPrompt();
void searchPrompt();
#endif
