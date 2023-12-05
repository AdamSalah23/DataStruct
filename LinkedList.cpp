// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

IList::IList() : m_count(0)
{

}


int IList::getSize() const
{
	return m_count;
	
}


bool IList::isEmpty() const
{
	if (m_count == 0) {
		return true;
	}



	return false;
	
}



PointerBasedLinkedList::PointerBasedLinkedList() : IList(), m_head(nullptr), m_tail(nullptr)
{

}


bool PointerBasedLinkedList::add(int val)
{
	return false;
	Node * tempPtr = new Node(val, nullptr);
	Node * curPtr = m_head;

	if (this->isEmpty()) {
		m_head = tempPtr;
		++m_count;
		return true;
	}
	while (curPtr->getNext() != nullptr) {
		curPtr = curPtr->getNext();
	}
	curPtr->setNext(tempPtr);
	++m_count;
	return true;
}

bool PointerBasedLinkedList::remove(int val)
{
	if (isEmpty()) {
	return false;
}
	Node * curPtr = m_head;
	Node * prevPtr = nullptr;
	Node * nextPtr;
	while (curPtr != nullptr) {
		if (curPtr->getItem() == val) {
			nextPtr = curPtr->getNext();
			if (prevPtr != nullptr) {
				prevPtr->setNext(nextPtr);
			}
			else {
				m_head = nextPtr;
			}
			curPtr->setNext(nullptr);
			delete curPtr;
			--m_count;
			return true;
		}
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
}




void PointerBasedLinkedList::clear()
{
	delete m_head;
	m_head = nullptr;
	m_count = 0;

	
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	clear();
	
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";
	Node * cur = m_head;
	while (cur != m_head) {
		if (str == "") {
			str = to_string(cur->getItem());
		}
		else {
			str = str + " " + to_string(cur->getItem());
		}
		cur->getItem();
	}
	

    
	return str;
}

ArrayBasedList::ArrayBasedList() : IList()
{
    m_count = 0;
	// you got it for free :)
}

bool ArrayBasedList::add(int val)
{
	if (m_count < 10) {
		m_values[m_count] = val;
		++m_count;
		return true;
	}
	else return false;
}
bool ArrayBasedList::remove(int val)
{
	for (int i = 0; i < m_count; i++) {
		if (m_values[i] == val) {
			--m_count;
			for (int j=i; j<m_count; j++) {
				m_values[j] = m_values[j+1];
			}
			return true;
		}
	}

	return false;
}
void ArrayBasedList::clear()
{
	m_count = 0;
}
ArrayBasedList::~ArrayBasedList()
{
	clear();
}

std::string ArrayBasedList::toString() const
{
	string str = "";
	for (int i = 0; i< m_count; i++) {
		if (str == " ") {
			str = to_string(m_values[i]);
		}
		else {
			str += " " + to_string(m_values[i]);
		}
	
	}

	return str;
}

// Group Member 1: Adam Adawi 60
// Group Member 2: Denis Gorbachev 40