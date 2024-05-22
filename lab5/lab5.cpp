#include <iostream>
#include "List.h"
using namespace std;

class HashSet
{
private:
	static const int size = 503;
	List <string> table[size];

	int hashFunc(const string& key) const
	{
		unsigned long hash = 0;
		for (char c : key)
		{
			hash = (hash * 37 + c) % size;
		}
		return hash % size;
	}
public:
	HashSet();
	~HashSet();
	void add(const string& data);
	void remove(const string& data);
	bool contains(const string& data);
	void clear();
	int count();
	string* ToArray();

};

HashSet::HashSet()
{
}

HashSet::~HashSet()
{
	clear();
}

void HashSet::add(const string& data)
{
	int index = hashFunc(data);
	if (!contains(data))
	{
		table[index].add(data);
	}
}

void HashSet::remove(const string& data)
{
	int index = hashFunc(data);
	int listSize = table[index].count();
	for (int i = 0; i < listSize; i++)
	{
		if (table[index].elementAt(i) == data)
		{
			table[index].removeAt(i);
			return;
		}
	}
}

bool HashSet::contains(const string& data)
{
	int index = hashFunc(data);
	for (int i = 0; i < table[index].count(); i++)
	{
		if (table[index].elementAt(i) == data)
		{
			return true;
		}
	}
	return false;
}

void HashSet::clear()
{
	for (int i = 0; i < size; i++)
	{
		table[i].clear();
	}
}

int HashSet::count()
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += table[i].count();
	}
	return total;
}

string* HashSet::ToArray()
{
	int total = count();
	string* array = new string[total];
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		int listSize = table[i].count();
		for (int j = 0; j < listSize; ++j)
		{
			array[index++] = table[i].elementAt(j);
		}
	}
	return array;
}

int main() 
{
	HashSet hashSet;
	int choice;
	string value;
	do
	{
		cout << "1. Add an element." << endl;
		cout << "2. Remove an element." << endl;
		cout << "3. Check if an element is in the hash set." << endl;
		cout << "4. Size of the hash set." << endl;
		cout << "5. Clear the hash set." << endl;
		cout << "6. Show all elements." << endl;
		cout << "0. Exit." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element you want to add: " << endl;
			cin >> value;
			hashSet.add(value);
			break;
		case 2:
			cout << "Enter the element to remove: " << endl;
			cin >> value;
			hashSet.remove(value);
			break;
		case 3:
			cout << "Enter the element to check: " << endl;
			cin >> value;
			if (hashSet.contains(value))
			{
				cout << "The element is in the hash set." << endl;
			}
			else
			{
				cout << "The element is not in the hash set." << endl;
			}
			break;
		case 4:
			cout << "The size of the hash set is: " << hashSet.count() << endl;
			break;
		case 5:
			hashSet.clear();
			cout << "The hash set is cleared." << endl;
			break;
		case 6:
		{
			string* elements = hashSet.ToArray();
			int count = hashSet.count();
			cout << "Elements in the hash set: ";
			for (int i = 0; i < count; ++i)
			{
				cout << elements[i] << " ";
			}
			cout << endl;
			delete[] elements;
			break;
		}
		case 0:
			break;
		default:
			cout << "Unknown command. Try again." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}
