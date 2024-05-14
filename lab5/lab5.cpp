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
	string* toArray();

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

string* HashSet::toArray()
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
	return 0;
}