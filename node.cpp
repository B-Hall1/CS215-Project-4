#include <iostream>
#include <iomanip>
#include "node.h"

//------------------------------------------
//         constructors & destructors
//------------------------------------------
node::node() {
	key = 0;
	data = "";
	next = dup = NULL;
} // constructor (default)

node::node(int k, string d) {
	key = k;
	data = d;
	next = dup = NULL;
} // constructor

node::~node() {
	if (next) delete next;
	if (dup) delete dup;
	cout << "NODE DESTRUCT: key=" << key << " data=" << data << endl;
} // destructor

  //------------------------------------------
  //                  print
  //------------------------------------------
void node::print() {
	// print the data for the current node
	cout << setw(8) << key << " = " << data << endl;

	// print the data for the duplicate nodes, indented
	node * p = dup;
	while (p) { // same as: while (p != NULL)
		cout << "           " << p->data << endl;
		p = p->dup;
	}
} // print()