#pragma once

// List element class template
class ListElement
{
public:
	// Element state
	int value;
	ListElement* next;
	ListElement* prev;
public:
	ListElement();
	ListElement(int _val, ListElement * _prev, ListElement * _next);
};

// Default constructor
ListElement::ListElement()
{
	next = nullptr;
	prev = nullptr;
}

// Constructor 2
ListElement::ListElement(int _val, ListElement* _prev = nullptr, ListElement* _next = nullptr)
{
	this->value = _val;
	this->prev = _prev;
	this->next = _next;
}
