

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	CharValue.insert(std::make_pair('a', 0));
	CharValue.insert(std::make_pair('b', 1));
	CharValue.insert(std::make_pair('c', 2));
	CharValue.insert(std::make_pair('d', 3));
	CharValue.insert(std::make_pair('e', 4));
	CharValue.insert(std::make_pair('f', 5));
	CharValue.insert(std::make_pair('g', 6));
	CharValue.insert(std::make_pair('h', 7));
	CharValue.insert(std::make_pair('i', 8));
	CharValue.insert(std::make_pair('j', 9));
	CharValue.insert(std::make_pair('k', 10));
	CharValue.insert(std::make_pair('l', 11));
	CharValue.insert(std::make_pair('m', 12));
	CharValue.insert(std::make_pair('n', 13));
	CharValue.insert(std::make_pair('o', 14));
	CharValue.insert(std::make_pair('p', 15));
	CharValue.insert(std::make_pair('q', 16));
	CharValue.insert(std::make_pair('r', 17));
	CharValue.insert(std::make_pair('s', 18));
	CharValue.insert(std::make_pair('t', 19));
	CharValue.insert(std::make_pair('u', 20));
	CharValue.insert(std::make_pair('v', 21));
	CharValue.insert(std::make_pair('w', 22));
	CharValue.insert(std::make_pair('x', 23));
	CharValue.insert(std::make_pair('y', 24));
	CharValue.insert(std::make_pair('z', 25));

	first = nullptr;
}

LinkedList::~LinkedList()
{
	delete first;
}


bool LinkedList::insElem(char caracter)
{
		
	if (containsElement(caracter))
		return false;

	listElem *current;

	if (first == nullptr || CharValue.at(first->character) >= CharValue.at(caracter))
	{
		listElem *newNode = new listElem();
		newNode->character = caracter;
		newNode->pos = 0;
		newNode->next = nullptr;
		first = newNode;
	}
	else
	{
		current = first;
		while (current->next != nullptr  &&
			   CharValue.at(current->next->character) < CharValue.at(caracter))
		{
			current = current->next;
		}
		listElem *newNode = new listElem();
		newNode->character = caracter;
		newNode->pos = current->pos + 1;
		
		newNode->next = current->next;
		current->next = newNode;

		//reorder positions				
		listElem *aux = newNode;
		if (aux->next != nullptr)
		{
			aux = aux->next;
			int pos = aux->pos;
			int i = 1;
			while (aux != nullptr)
			{
				aux->pos += i;
				
				if (aux->next == nullptr)
					break;
				aux = aux->next;
			}
		}				
	}
	
	return false;
}

bool LinkedList::containsElement( char elem)
{
	listElem *aux = first;

	if (aux == nullptr)
		return false;

	if (aux->character == elem)
		return true;

	while (aux->next != nullptr)
	{
		if (aux->character == elem)
			return true;

		aux = aux->next;
	}
	
	return false;
}

std::vector<std::pair<char, int>> LinkedList::getElemets()
{
	listElem *aux = first;
	std::vector<std::pair<char, int>> elements;

	while (aux != nullptr)
	{		
		elements.push_back(std::make_pair(aux->character, aux->pos));

		if (aux->next == nullptr)
			break;
		aux = aux->next;
	}

	return elements;
}

void LinkedList::printList()
{
	listElem *aux = first;
		
	std::cout << "L = ";
	while (aux != nullptr)
	{					
		std::cout << "( " << aux->character << ", " << aux->pos << "),";
		if (aux->next == nullptr)
			break;
		aux = aux->next;
	}
	std::cout << std::endl;
}

bool LinkedList::hasLoop()
{

	listElem *iterator = first;
	listElem *doubleIterator = first;
	
	if (iterator == nullptr)
		return false;
			
	while (true)
	{
		iterator = iterator->next;

		if (doubleIterator->next != nullptr)
			doubleIterator = doubleIterator->next->next;
		else
			return false;

		if (iterator == nullptr || doubleIterator == nullptr)
			return false;

		if (iterator->character == doubleIterator->character)
			return true;
		
	}	
	
	return false;
}
