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
	ListElement* go_to_first();
	void print_list();
	void add_to_end(int val);
	void add_after(int val);
	// Test methods
	int count_elements();
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

// Find and return first element in chain
ListElement* List2D::go_to_first()
{
	if (this->is_empty()) return nullptr;
	while (p_current->prev != nullptr) {
		p_current = p_current->prev;
	}
	return p_current;
}


// Print the whole list (all elements)
void List2D::print_list()
{
	// Check if the list is empty
	if (this->is_empty()) {
		std::cout << "The list is empty" << std::endl;
		return;
	}
	go_to_first();
	do {
		std::cout << p_current->value << "; ";
	} while ( (p_current->next != nullptr) ? (p_current = p_current->next) : false);
}



// Add new element to the end of chain
void List2D::add_to_end(int val)
{
	go_to_last();
	ListElement * created_element = new ListElement(val, p_current);
	if (p_current != nullptr) p_current->next = created_element;
	p_current = created_element;
}

// Add new element after the current
void List2D::add_after(int val)
{
	// If current is last or the list is empty
	// then we just have to add to the end
	if ((p_current == nullptr) || (p_current->next == nullptr)) {
		this->add_to_end(val);
		return;
	}
	// If current have next element(s)
	// then we need to rebase pointers
	ListElement* created_element = new ListElement(val, p_current);
	created_element->next = p_current->next;
	p_current->next = created_element;
	created_element->prev = p_current;
	(created_element->next)->prev = created_element;
	p_current = created_element;
}


// Count of elements in the list
int List2D::count_elements()
{
	ListElement* temp_current = p_current;
	if (is_empty()) return 0;
	int n = 1;
	go_to_first();
	while (p_current->next != nullptr) {
		p_current = p_current->next;
		n++;
	}
	p_current = temp_current;
	return n;
}