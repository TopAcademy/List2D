
#include <iostream>
#include "List2D.h"
using std::cout;
using std::endl;

int main()
{
	List2D list1;
	list1.add_after(0);
	list1.add_to_end(10);
	list1.add_to_end(50);
	list1.add_to_end(120);
	list1.go_to_first();
	list1.add_after(1);
	list1.go_to_last();
	list1.add_after(8000);
	list1.print_list();
	cout << list1.count_elements() << endl;
}
