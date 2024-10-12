#include <iostream>
#include <string>
#include "dataStructure.h"

using namespace linkedList;
int main(){
	// Initialize a new linked list
    LinkedList<int> list1;

    // Insert elements at the end
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    // Insert element at the beginning
    list1.insertAtBeginning(5);

    // Insert element at a specific position
    list1.insertAtPosition(15, 3);

    cout << "Linked list after insertions: ";
    list1.display();

    // Delete element from the beginning
    list1.deleteFromBeginning();
    cout << "Linked list after deleting from beginning: ";
    list1.display();

    // Delete element from the end
    list1.deleteFromEnd();
    cout << "Linked list after deleting from end: ";
    list1.display();

    // Delete element from a specific position
    list1.deleteFromPosition(2);
    cout << "Linked list after deleting from position 2: ";
    list1.display();
	return 0;
}

