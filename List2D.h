#pragma once
#include <iostream>
#include "ListElement.h"

// Two-directional-List class template

class List2D
{
private:
	// State variables
	ListElement * p_current;
public:
	// Constructor, destructor
	List2D();
	// Other methods
	bool is_empty();
	ListElement* go_to_last();
	void add_to_end(int val);

};

// Default constructor
List2D::List2D()
{
	p_current = nullptr;
}

// Returns true if List doesn't have elements
bool List2D::is_empty()
{
	if (!p_current) return true;
	else return false;
}

// Find and return last element in chain
ListElement* List2D::go_to_last()
{
	if (this->is_empty()) return nullptr;
	while (p_current->next != nullptr) {
		p_current = p_current->next;		// Go to next
	}
	return p_current;
}


// Add new element to the end of chain
void List2D::add_to_end(int val)
{
	go_to_last();
	ListElement * created_element = new ListElement(val, p_current);
	if (p_current != nullptr) p_current->next = created_element;
	p_current = created_element;
}

