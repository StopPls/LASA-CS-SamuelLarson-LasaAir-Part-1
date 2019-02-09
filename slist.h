#pragma once
/*

Header file for single linked list class library

*/



#ifndef SLIST_H
#define SLIST_H
#include <string>






struct Node {
	void* value;
	Node* next;
};

class slist {
private:
	Node* head;
	int length;

public:
	slist();

	~slist();

	void add(void* value);
	//Adds a new value to the end of this list.

	void clear();			
	//Removes all elements from this list.

	bool equals(slist list);			
	//Returns true if the two lists contain the same elements in the same order.

	void* get(int index);				
	//Returns the element at the specified index in this list.

	void insert(int index, void* value);		
	//Inserts the element into this list before the specified index.

	void exchg(int index1, int index2);		
	//Switches the payload data of specified indexex.

	bool isEmpty();				
	//Returns true if this list contains no elements.

	//void mapAll(void (*f)(Airport))	;			
	//Calls the specified function on each element of the linkedlist in ascending index order.

	void remove(int index);		
	//Removes the element at the specified index from this list.

	void set(int index, void* value);		
	//Replaces the element at the specified index in this list with a new value.

	int size();					
	//Returns the number of elements in this list.

	slist subList(int start, int length);	
	//Returns a new list containing elements from a sub-range of this list.

	std::string toString();				
	//Converts the list to a printable string representation.
};



#endif