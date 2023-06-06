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



