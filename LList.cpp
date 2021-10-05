#include <iostream>
#include "LList.h"

//----------------------------------------------------
//	           constructor & destructor
//----------------------------------------------------
LList::LList() {
	head = NULL;
}
LList::~LList() {
	if (head) delete head;
}

//----------------------------------------------------
//				    print
//----------------------------------------------------
// prints each node in the list, or EMPTY when there
// are no nodes to print
//----------------------------------------------------
void LList::print() {
	if (head == NULL)
		cout << "EMPTY\n\n";
	else {
		node * p;
		p = head;
		while (p != NULL) {
			p->print();
			p = p->next;
		}
		cout << endl;
	}
} // print()

  //----------------------------------------------------
  //				         search
  //----------------------------------------------------
  // Given: key to search for
  // Returns: pointer to a node in the list found to have
  //          the given search key, or NULL for not found
  //----------------------------------------------------
node * LList::search(int srchKey) {
	node* p = head;
	while (p != NULL) {
		if (p->key == srchKey) {
			return p;
		}
			p = p->next;
		}
	return NULL;
	
} // search()

  //----------------------------------------------------
  //				   findNode
  //----------------------------------------------------
  // Given: a key to search for
  // Searches for a node with the given key, and if 
  // found, invokes the print() method in the found node.
  // Otherwise, prints "not found"
  //----------------------------------------------------
void LList::findNode(int srchkey) {
	node* p = search(srchkey);
	if (p == NULL) {
		cout << "not found" << endl;
	}
	else
		p->print();
		
} // findNode()

  //----------------------------------------------------
  //				    getb4
  //----------------------------------------------------
  // Given: a pointer to a node in the list
  // Returns: a pointer to the node in the list BEFORE
  //               the one pointed to by r, OR
  //          NULL when r is the head or not found in
  //               the list
  //----------------------------------------------------
node * LList::getb4(node * r) {
	node* p = head;
	if (r == head) {
		return NULL;
	}
	if (r == NULL) {
		return NULL;
	}
	while (p->next != NULL) {
		if (p->next == r) {
			return p;
		}
		p = p->next;
	}
	return NULL;
} // getb4()

  //----------------------------------------------------
  //				       insert
  //----------------------------------------------------
  // Given: key and data for a new node
  // Allocates/populates a new node
  // When a node with the same key already exists:
  //     the current/old node is replaced by the new one
  //     and the old one is placed on the new one's 
  //     duplicate list.
  // Otherwise, the new node is prepended to the head
  //     of the list.
  //----------------------------------------------------
void LList::insert(int k, string d) {
	node * n = search(k);
	node * b4 = getb4(n);

	if (head == NULL) {
		head = new node(k, d);
	}
	else if (search(k) == NULL) {
		node* temp = head;
		head = new node(k,d);
		head->next = temp;
	}
	else {
	node * newNode = new node(k, d);

	if (b4 == NULL) {
		newNode->next = head->next;
		node* temp = head;
		head = new node;
		newNode->dup = head;
	}
	else {
		b4->next = newNode;
		newNode->next = n->next;
		newNode->dup = n;
	}
	}
} // insert()

  //----------------------------------------------------
  //				       remove
  //----------------------------------------------------
  // Given: a pointer to a node in the list to be removed
  //        BUT NOT DELETED/DESTROYED
  // Returns: TRUE - when the node was successfully removed
  //          FALSE - when the given node is NULL or the node
  //                  is not actually in the list.
  // Simply removes the node from the linked list.
  // (including setting the NEXT pointer in the node to NULL)
  //----------------------------------------------------
bool LList::remove(node * r) {
	if (r == NULL || r != search(r->key) ) {
		return false;
	}
	node * b4 = getb4(r);
	if (b4 == NULL) {
		head = r->next;
		r->next = NULL;
	}
	else {
		b4->next = r->next;
		r->next = NULL;
	}
	return true;
} // remove()

  //----------------------------------------------------
  //				       drop
  //----------------------------------------------------
  // Given: key of a node to drop
  // Returns: TRUE when a node was found and deleted
  //          FALSE when a node with the given key not found,
  //                or the remove() fails.
  // Searches for a node in the list with the given key:
  // When found, removes and deletes the node
  //----------------------------------------------------
bool LList::drop(int k) {
	node * n = search(k);
	if (n == NULL) {
		return false;
	}
	
	if (!remove(n)) {
		return false;
		
	}
	delete n;
		return true;
} // drop()

  //----------------------------------------------------
  //				        max
  //----------------------------------------------------
  // Returns: a pointer to the node with the highest key
  //          or NULL when there list is empty.
node * LList::max() {
	int maxKey = 0;
	node * maxNode = NULL;
	node * p = head;
	while (p != NULL) {
		if (p->key > maxKey) {
			maxKey = p->key;
			maxNode = p;
			
		}
		p = p->next;
	}
	
	return maxNode;
} // max()

  //----------------------------------------------------
  //				       sort
  //----------------------------------------------------
  // Sorts the list in descending order by key values
void LList::sort() {
	node * j ;
	node * newHead = NULL;

	while (head != NULL) {
		j = max();
		remove(j);
		j->next = newHead;
		newHead = j;
	}

	head = newHead;
} // sort()