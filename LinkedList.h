#pragma once
#include <map>
#include <vector>


class LinkedList
{
	 struct listElem {
		char character;
		int pos;
		struct listElem *next;
	};

	 std::map <char, int> CharValue;	
	 listElem *first;

public:

	LinkedList();

	virtual ~LinkedList();	

	bool insElem( char element);

	bool containsElement( char elem);

	std::vector<std::pair<char,int> > getElemets();

	void printList();

	bool hasLoop();


};