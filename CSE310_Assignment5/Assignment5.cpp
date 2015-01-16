/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am

	NOTE: Refer to HashTable.cpp, for Insert() & Hash() analysis.
*/
#include "Assignment5.h"

int main()
{
	//Prompts for hashTable size and instantiates the hastTable - Ends when a blank line is read.
	sizePrompt();

	//Parsing & Insertion - Ends when a blank line is read. Prints the HashTable.
	insertPrompt();

	//Prompts for a zipCode and searches for the matching item in the table. - Ends when a blank line is read.
	searchPrompt();

	delete m_hashTable;

	return 1;
}

/*
	Copies and removes the token specified by the delimeter from the parameter string. Returns the token.
	The delimeter is specified in "Assignment5.h"
*/
string extractToken(string* input)
{
	string token = input->substr(0, input->find(m_delimeter));
	m_temp = input->substr(input->find(m_delimeter) + 1, input->length());
	return token;
}

void sizePrompt()
{
	cout << "Input the size of the array." << endl;
	cin >> m_hashTableSize;
	m_hashTable = new HashTable(m_hashTableSize);

	//Flush the stream.
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	if (m_hashTable != NULL)
		cout << "\nHashtable initialized with a size of " << m_hashTableSize << ". Press enter to proceed." << endl;

	//There should be an empty space according to the format specified in the documentation.
	getline(cin, m_input);
	if (m_input.empty())
		cout << "\nNewline read. Proceeding to parsing & insertion.\n\tFormat is: zipCode, City, State\n" << endl;
}

void insertPrompt()
{
	do
	{
		getline(cin, m_input);
		if (m_input.empty())
			cout << "\nEmpty space read. Proceeding to Printing." << endl;

		int success;
		if (!m_input.empty())
		{
			m_temp = m_input;

			//Extracts the zipCode token and removes the token from the temp string.
			m_zipCode = extractToken(&m_temp);

			//Extracts the city token and removes the token from the temp string.
			m_city = extractToken(&m_temp);

			//The remaining teken in the temp string should be the state.
			m_state = m_temp;

			if (m_hashTable->isFull())
				cout << "\nHashtable is full. Insert() failed.\n" << endl;
			else
			{
				success = m_hashTable->Insert(m_zipCode, m_city, m_state, 0);

				if (success != -1)
					cout << "\nNode successfully inserted at " << success << endl;
				else
					cout << "\nInsert() failed. Hash function reached limit of " << m_hashTable->getSize() << "\n" << endl;
			}
		}
	} while (!m_input.empty());

	//Print the inserted elements as specified by the documentation.
	cout << "\nPrinting Hashtable." << endl;
	m_hashTable->print();
}

void searchPrompt()
{
	cout << "\nEnter the area code you are searching for." << endl;
	getline(cin, m_input);

	while (!m_input.empty())
	{
		int resultIndex;
		resultIndex = m_hashTable->Search(m_input, 0);

		if (resultIndex == -1)
			cout << m_input << " not found." << endl;
		else
		{
			cout << m_input << " is for the city of " << m_hashTable->getLocationArray()[resultIndex].getLocation()->getCity() <<
				" in " << m_hashTable->getLocationArray()[resultIndex].getLocation()->getState() << endl;
		}
		getline(cin, m_input);
	}
}
