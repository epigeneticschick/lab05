/*
 * List.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: llw5
 */

#include "List.h"
#include <stdexcept>

using namespace std;
List::List(){
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}
List::Node::Node() {
	myItem = Item();
	myNext = NULL;
}

List::Node::Node(Item it, Node*next){
	myItem = it;
	myNext = next;

}

//Accessor for Size
unsigned List::getSize() const{
	return mySize;
}

//Accessor for myFirst
Item List::getFirst() const{
	if(mySize < 0 || myFirst == NULL){
		throw underflow_error("There is no First Node!");
	}
	else{
	return myFirst->myItem;
	}
}

//Accessor for myLast
Item List::getLast() const{
	if(mySize < 0 || myFirst == NULL){
			throw underflow_error("There is no First Node!");
		}
		else{
		return myLast->myItem;
		}
}

void List::append(const Item& it){
	 Node *nodePtr= new Node(it, NULL);
	if(myFirst == NULL){
		myFirst = nodePtr;

	}
	else{
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize += 1;
}

List::~List() {
   delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
   myFirst = myLast = NULL; // clear myFirst and myLast (optional)
   mySize = 0;              // clear mySize (optional)
}

List::Node::~Node() {
	cout << "~Node() is deallocating the node containing item "
	             << myItem << endl;
    delete myNext;       // delete the next node, invoking ~Node() in it
                      // (does nothing if myNext == NULL)
 }
List::List(const List& original) {
     myFirst = myLast = NULL;       //  set pointers
     mySize = 0;                    //   and size to 'empty' values
     Node* oPtr = original.myFirst; //  start at the first node
     while (oPtr != NULL) {         //  while there are nodes to copy:
        append(oPtr->myItem);       //   append the item in that node
        oPtr = oPtr->myNext;        //   advance to next node
     }
  }
List& List::operator=(const List& original){
if (myFirst != original.myFirst){
	myFirst = myLast = NULL;       //  set pointers
	delete myFirst;
	mySize = 0;                    //   and size to 'empty' values
	     Node* nPtr = original.myFirst; //  start at the first node
	     while (nPtr != NULL) {         //  while there are nodes to copy:
	        append(nPtr->myItem);       //   append the item in that node
	        nPtr = nPtr->myNext;        //   advance to next node
	     }
}
	return *this;
}
