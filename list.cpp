
//====================================================
// Anish Banswada
// November 2022
// List.cpp
// This is the class method implementation file for
// List linked list implementation
//=======================================================
#include <iostream>
#include <string>
#include "List.h"
//=================================================
// default constructor
// Creates a new empty linked list 
//  Parameters : None
//  Return value : None
//===================================================
template <class T>
List<T>::List ( void )
{
head =  NULL;
}
//=========================================================
// Copy constructor
// Create a new List from an existing one
// Parameters : The list that is to be copied
// Return value : A copy of the list
//=========================================================
template <class T>
List<T>::List ( const List<T> &mylist )
{
Node *qtr = mylist.head;
if (qtr == NULL)
{
head = NULL;
}
else
{
Node *ptr = new Node;
head = ptr;
while (qtr->next != NULL)
{
ptr->item = qtr->item;
ptr->next = new Node;
ptr = ptr->next;
qtr = qtr->next;
} 
ptr->next = NULL;
ptr->item = qtr->item;
}
}
//====================================================
// Assignment operator 
// Copies the assigned  linked list into the caller object
// Parameters : The list that is to be copied
// Return Value : A pointer to the caller object that is a copy of the parameter
//=====================================================
template <class T>
List<T> List<T>::operator= ( const List<T> &mylist )
{
Node *temp = head; 
while (temp != NULL)
{
temp = temp->next;
delete head;
head = temp;
}
Node *qtr = mylist.head;
if (qtr == NULL)
{
head = NULL;
}
else
{
Node *ptr = new Node;
head = ptr;
while (qtr->next != NULL)
{
ptr->item = qtr->item;
ptr->next = new Node;
ptr = ptr->next;
qtr = qtr->next;
} 
ptr->next = NULL;
ptr->item = qtr->item;
}
return *this;
}
//====================================================
// Destructor
// Cleans up the memory of the list by deleting all the 
// nodes
// Parameters: None 
// Return value : None
//=====================================================
template <class T>
List<T>::~List ( void )
{
Node *temp = head; 
while (temp != NULL)
{
temp = temp->next;
delete head;
head = temp;
}
}
//====================================================
// to_string
// Converts list into a string to be printed out
// Parameters: None
// Return value : Elements in the list as a string
//=====================================================
template <class T>
string        List<T>::to_string( void ) const
{
    stringstream stream;
    Node *ptr = head;
    while(ptr != NULL)
    {
        stream << ptr->item << " ";
        ptr = ptr->next;
    }
    return stream.str();
}
//====================================================
// append
// Appends a new item onto the back of the linked list
// Parameters : item of type T that is to be appended to the list
// Return Value : None
//=====================================================
template <class T>
void List<T>::append( const T &item )
{
Node *qtr;
qtr = new Node;
qtr->item = item;
qtr->next = NULL;
if (head == NULL)
head = qtr;
else
{
Node *ptr = head;
while (ptr->next != NULL)
{
ptr = ptr->next;
}
ptr->next = qtr;
}
}
//====================================================
// insert
// Inserts a new value at the specified position.
// Parameters : T item that is to be inserted, 
// int index - the location of the insert
// Return Value : None
//=====================================================
template <class T>
void List<T>::insert( const T &item, int index )
{
if(0>index)
{
cout << "INVALID INDEX" << endl;
exit(0);
}
Node *qtr = new Node;
qtr->item = item;
qtr->next = NULL;
if (index == 0)
{
qtr->next = head;
head = qtr;
}
else
{
Node *ptr = head;
while (index > 1)
{
if (ptr->next == NULL)
{
cout << "INDEX OUT OF BOUNDS" << endl;
exit(0);
}
ptr = ptr->next;
index--;
}
qtr->next = ptr->next;
ptr->next = qtr;
} 
}
//====================================================
// remove
// Removes an item at the specified location.
// Parameters : int index - the position where the value 
// is to be removed
// Return value : None
//=====================================================
template <class T>
void List<T>::remove( int index )
{
if(0>index)
{
cout << "INVALID INDEX" << endl;
exit(0);
}
if (index == 0)
{
Node *ptr = head;
head = ptr->next;
delete ptr;
ptr = NULL;
}
else
{
Node *ptr = head;
Node *qtr = head;
while (index > 0)
{
if (qtr->next == NULL)
{
cout << "INDEX OUT OF BOUNDS" << endl;
exit(0);
}
ptr = qtr;
qtr = qtr->next;
index--;
} 
ptr->next = qtr->next;
delete qtr;
qtr = NULL;
}
}
//====================================================
// clear
// Removes all items from the list.
// Parameters : None
// Return value : None
//=====================================================
template <class T>
void List<T>::clear ( void )
{
Node *temp = head; 
while (temp != NULL)
{
temp = temp->next;
delete head;
head = temp;
}
head = NULL;
}
//====================================================
// operator []
// Returns item at specified location
// Parameters :  int index - the position where the value is to be returned
// Return value : item of type T at the specified location
//=====================================================
template <class T>
T & List<T>::operator[] ( int index )
{
if (0 > index)
{
cout << "INVALID INDEX" << endl;
exit(0);
}
if (index == 0)
return (head->item);
else
{
Node *ptr = head;
while (index > 0)
{
ptr = ptr->next;
if (ptr == NULL)
{
cout << "INDEX OUT OF BOUNDS" << endl;
exit(0);
}
index--;
} return (ptr->item);
}
}
//====================================================
// operator +
// Concatenates two lists into a new list. Does not change either existing
// lists.
// Parameters : mylist- a List of type T
// Return value : The concatenation of the caller object and mylist
//=====================================================
template <class T>
List<T> List<T>::operator+( const List<T> &mylist ) const
{
List <T> l1;
Node *ptr = head;
Node *qtr = mylist.head;
while (ptr != NULL)
{
l1.append(ptr->item);
ptr = ptr->next;
}
while (qtr != NULL)
{
l1.append(qtr->item);
qtr = qtr->next;
}
return l1;
}
//====================================================
// length
// Returns the number of items in the list.
// Parameters: None
// Return value : int - size of the array
//=====================================================
template <class T>
int List<T>::length( void ) const
{
int len = 0;
Node *ptr = head;
while (ptr != NULL)
{
ptr = ptr->next;
len++;
}
return len;
}
//====================================================
// isEmpty
// Returns true if the list is empty, false otherwise.
// Parameters: None 
// Return value : Boolean -  true if the list is empty, false otherwise
//=====================================================
template <class T>
bool List<T>::isEmpty( void ) const
{
return(head == NULL);
}
