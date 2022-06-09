// Linked Lists

// Author: Zinet Hyssen
// Date: April 9, 2021

// This program uses a linked list class with two member functions and a
// default constructor: void add(double x), boolean isMember(double x), 
// LinkedList(). The add function will add a new node to the front of the 
// list and the isMember function will check to see if the value x is in 
// list.

#include <iostream>

using namespace std;

// ListNode Class
class ListNode
{
public:
	ListNode(double v, ListNode* n)
	{
		value = v; next = n;
	}
private:
	double value;
	ListNode* next;
	friend class LinkedList;
};

// LinkedList Class
class LinkedList
{
public:
	void add(double x);
	bool isMember(double x);
	LinkedList() { head = NULL; }
	~LinkedList();
private:
	ListNode* head;
};

// LinkedList::add - Add a value to the list
void LinkedList::add(double x)
{
	// Add value to the front of the list
	ListNode* n = new ListNode(x, head);
	head = n;
}

// LinkedList::isMember - Check value to see if it is a member of the list
bool LinkedList::isMember(double x)
{
	ListNode* n = head;
	// Look through list to check for value
	while (n != nullptr) {
		if (n->value == x) return true;
		n = n->next;
	}
	return false;
}

// Destructor
LinkedList::~LinkedList()
{
	while (head != 0)
	{
		ListNode* n = head;
		head = head->next;
		delete n;
	}
}

// Main Function
int main()
{
	// Describe program
	cout << "This program creates a list of five numbers with decimal points.";
	cout << "Then it will allow the user to check if other numbers are in the list.\n";

	// Create empty list
	LinkedList list;

	// User input
	cout << "Enter 5 numbers with decimal points:\n";
	for (int i = 1; i <= 5; i++)
	{
		double x;
		cin >> x;
		list.add(x);
	}

	cout << "The program will now check new number entries ";
	cout << "to see if they are on the list.\n";

	// Test for list membership
	for (int i = 1; i <= 5; i++)
	{
		double x;
		cout << "Enter a new number with a decimal point: ";
		cout << "(You may use a number previously entered.)\n";
		cin >> x;
		if (list.isMember(x))
		{
			cout << x << " is on the list." << endl;
		}
		else
			cout << x << " is not on the list." << endl;
	}

	// pause to grab screenshot
	system("Pause");

	return 0;
}