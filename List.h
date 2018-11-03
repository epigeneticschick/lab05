/*
 * List.h
 *
 *  Created on: Oct 9, 2018
 *      Author: llw5
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>

using namespace std;

typedef double Item;

class List {
public:
	List();
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	~List();
	List(const List& original);
	 List& operator=(const List& original);
private:
	struct Node {
	Item myItem;
	Node*myNext;
	Node();
	Node(Item it, Node*next);
	~Node();
	};

	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	friend class ListTester;
};



#endif /* LIST_H_ */
