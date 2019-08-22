#include <iostream>
#include <string>
#include "CharList.h"

using namespace std;


CharList::CharList(string s)
{
	head = NULL;
	tail = NULL;
	size = 0;
};

bool CharList::empty()
{
	return (size==0) ? 1 : 0;
}

int CharList::size()
{
	return size;
}

void CharList::insert(char c)
{
	node *temp = new node;
	temp->letter = c;
	temp->headptr = NULL;
	temp->tailptr = head;
	head = temp;
}

void CharList::append(char c)
{
	node *temp = new node;
	temp->letter = c;
	temp->headptr = tail;
	temp->tailptr = NULL;
	tail = temp;
}

void CharList::insert(char c, char d)
{
	node *p, *temp;
	*temp = new node;
	temp->letter = c;
	p = head;
	for (p = head; p != NULL; p = p->headptr)
	{
		if (p->letter == d)
		{
			temp->headptr = p->headptr;
			temp->tailptr = p;
			p->headptr = temp;
			return;
		}
	}
	append(c);
}

void CharList::append(char c, char d)
{

}

void CharList::insert(char c, char d, int n)
{

}

void CharList::append(char c, char d, int n)
{

}

void CharList::remove(char c)
{
	node *p
	for (p = head; p != NULL; p = p->headptr)
	{
		if (p->letter == c)
		{
			(p->headptr)->tailptr = p->tailptr;
			(p->tailptr)->headptr = p->headptr;
			delete p;
		}
	}
}

void CharList::remove(char c, int n)
{
	node *p;
	if (n < 1) {
		cout<<"insances must be 1 and greater"<<endl;
		return;
	}
	for (p = head; p != NULL; p = p->headptr)
	{
		if (p->letter == c)
		{
			if (n == 1) {
				(p->headptr)->tailptr = p->tailptr;
				(p->tailptr)->headptr = p->headptr;
				delete p;
			}
			else {
				n--;
			}
		}
	}
}

string CharList::toString()
{
	node *p;
	char *word;
	int j = 0;
	if (empty()) {
		cout<<"No characters to list"<<endl;
		return NULL;
	}

	word = new char[size];
	/* Using for loop instead of while loop. May fail*/
	for (p = head; p != NULL; p = p->headptr)
	{
		word[j++] = p->letter;
	}
	return word;
}

CharList::~CharList()
{
	node *temp;
	for (int i = 0; i < size; i++) {
		temp = head
		head = head->headptr;
		delete temp;
	}
}
