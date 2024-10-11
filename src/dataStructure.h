#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE

#include <iostream>
using namespace std;

namespace linkedList{
	template <class T>
	struct Node {
		T data;  
		Node<T>* next; 
	};

	template <class T>
	class LinkedList {
	    Node<T>* head;
	
		public:
			LinkedList() : head(nullptr) {}
			Node<T>* getValue(){
				return head;
			}

			void insertAtBeginning(T value) {
				Node<T>* newNode = new Node<T>(); 
				newNode->data = value;      
				newNode->next = head;      
				head = newNode;            
			}

			void insertAtEnd(T value) {
				Node<T>* newNode = new Node<T>();  
				newNode->data = value;   
				newNode->next = nullptr;       

				if (!head) {
					head = newNode;
					return;
				}

					Node<T>* temp = head;
				while (temp->next) {
					temp = temp->next;
				}

				temp->next = newNode;
			}

			void insertAtPosition(T value, int position) {
				if (position < 1) {
					return;
				}

				if (position == 1) {
					insertAtBeginning(value);
					return;
				}

				Node<T>* newNode = new Node<T>();  
				newNode->data = value;     

				Node<T>* temp = head;
				for (int i = 1; i < position - 1 && temp; ++i) {
					temp = temp->next;
				}

				// If the position is out of range, print an error message
				if (!temp) {
					//cout << "Position out of range." << endl;
					delete newNode;
					return;
				}

				// Insert the new node at the desired position
				newNode->next = temp->next;
				temp->next = newNode;
		}

			// Function to Delete the first node of the list
			void deleteFromBeginning() {
				if (!head) {
					cout << "List is empty." << endl;
					return;
				}

				Node<T>* temp = head; 
				head = head->next; 
				delete temp;      
			}

			// Function to Delete the last node of the list
			void deleteFromEnd() {
				if (!head) {
					cout << "List is empty." << endl;
					return;
				}

				if (!head->next) {
					delete head;   
					head = nullptr;   
					return;
				}

				// Traverse to the second-to-last node
				Node<T>* temp = head;
				while (temp->next->next) {
					temp = temp->next;
				}
				
				//  Delete the last node
				delete temp->next; 
				// Set the second-to-last node's next to nullptr
				temp->next = nullptr; 
			}

			// Function to Delete a node at a specific position in the list
			void deleteFromPosition(int position) {
				if (position < 1) {
					cout << "Position should be >= 1." << endl;
					return;
				}

				if (position == 1) {
					deleteFromBeginning();
					return;
				}

				Node<T>* temp = head;
				for (int i = 1; i < position - 1 && temp; ++i) {
					temp = temp->next;
				}

				if (!temp || !temp->next) {
					cout << "Position out of range." << endl;
					return;
				}
				// Save the node to be deleted
				Node<T>* nodeToDelete = temp->next; 
				// Update the next pointer
				temp->next = temp->next->next;   
				// Delete the node
				delete nodeToDelete;            
			}

			void run(){
				
			}

			// Function to print the nodes of  the linked list
			void display() {
				if (!head) {
					cout << "List is empty." << endl;
					return;
				}

				Node<T>* temp = head;
				while (temp) {
					cout << temp->data << " -> "; 
					temp = temp->next;
				}
				cout << "nullptr" << endl; 
			}

			// Function to run through the Linked list 
			
		
	};
	

}

namespace Set{
	template <class T>
	struct Value{
		T value;
		string unit;
	};    

	template <class T>
	struct DataAttribute {
		string field;
		T value;
	};
}

#endif
