#include "slist.h"
#include "math.h"
#include "iostream"
/*

Class Library File

*/
using namespace std;


slist::slist() 
{

	length = 0;

}

slist::~slist() 
{

	clear();

}

//add stuff
void slist::add(void* value) 
{

	if(!isEmpty()) 

	{

		Node* current = head;

		for(int x = 1; x < size(); x++) 
		{
			current = current->next;
		}
		Node* n = new Node;
		n->value = value;
		current->next = n;
		length++;
	}

	else
	{
		head = new Node;
		head->value = value; 
		head->next = new Node();
		length++;

	}

}	

//clear the list
void slist::clear() {

	Node* current = head;
	Node* previous = head;

	for(int i=0; i<length; i++)
	{

		delete previous;
		previous = current; 
		current = current -> next;

	}
	length = 0;

}

bool slist::equals(slist list)
{		

	if(size() == list.size()) 
	{

		for(int x = 0; x < size(); x++)
		{

			if(get(x) != list.get(x))
			
			{
				return false;
			}

		}

	}
	else return false;
	return true;

}

void* slist::get(int index)
{		
	Node* cur = head;
	for(int x = 0; x < index; x++) 
	{
		cur = cur->next;
	}
	return cur->value;

}


void slist::insert(int index, void* value) 
{		

	Node* cur = head;
	for(int x = 0; x < index; x++) 
	{
		cur = cur->next;
	}
	Node* qqq = head;
	qqq->value = value;
	qqq->next = cur->next;
	cur->next = qqq;
}

void slist::exchg (int index1, int index2)
{

	Node* epic1 = nullptr;
	Node* epic2 = nullptr;
	for (int i = 0; i < index1; i++)
	{

		epic1 = epic1->next;
		for (int j = 0; j < index2; j++)
		{
			epic2 = epic2->next;
			Node* notepic = epic1;
			epic1 = epic2;
			epic2 = notepic;
		}
	}
}

bool slist::isEmpty()
{
	if (length!=0)
	{
		return false;
	}
	return true;
}

void slist::remove(int index) 
{			
	Node* cur = head;
	Node* prev = head;
	for(int x = 0; x < index; x++) 
	{
		cur = cur->next;
	}
	for(int x = 0; x < index; x++) 
	{
		prev = prev->next;
	}
	prev->next = cur->next;
	delete cur;
}

void slist::set(int index, void* value)
{		
	Node* cur = head;
	for(int x = 0; x < index; x++)
	{
		cur = cur->next;
	}
	cur->value = value;
}

//tells you datasize
int slist::size() {
	return length;
}

//baby lists
slist slist::subList(int start, int length)
{ 

	Node* cur = head;
	slist val;

	for(int x = 0; x < start; x++)
	{
		cur = cur->next;
	}

	for(int x = 0; x < length; x++) 
	{
		val.add(cur->value);
		cur = cur->next;
	}
	return val;
}

//the stringamajig
string slist::toString()
{
	Node* curr = head;
	std::cout << length + "/n";

	for(int x=0; x<length; x++)
	{
		std::cout << curr;
		curr = curr -> next;
	}

	return "complete";
}