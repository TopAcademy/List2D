
#include <iostream>
#include "List2D.h"
using std::cout;
using std::endl;

int main()
{
	List2D list1;
	list1.add_to_end(10);
	list1.add_to_end(50);
	list1.add_to_end(120);
	list1.add_before(80);
	list1.print_list();
	cout << endl << "Found element: " << list1.find(50)->value << endl;
	
}
