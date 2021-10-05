//-----------------------------------------------------------
//						CS 215 – Spring 2018
//							Project 4
//-----------------------------------------------------------
// Author: <Blair Hall>
// Section: <004>
// Description:Implementation of a dynamic list data structure
// Assistance: I received help from the following: 
// Thomas Barber
//-----------------------------------------------------------
#include <iostream>
#include "LList.h"

//-----------------------------------------------------------
//                        askAction
//-----------------------------------------------------------
char askAction() {
	string userinput;
	cout << "\nTEST MENU:\n";
	cout << "I - Insert\n";
	cout << "D - Delete (Drop)\n";
	cout << "P - Print List\n";
	cout << "F - Find\n";
	cout << "S - Sort\n";
	cout << "X - Exit\n";
	cout << "==> ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, userinput);
	return toupper(userinput[0]);
} // askAction()

  //-----------------------------------------------------------
  //                        testInsert
  //-----------------------------------------------------------
void testInsert(LList & L) {
	int key;
	string data;
	cout << "Enter key:  ";
	cin >> key;
	cout << "Enter data: ";
	cin.ignore();
	getline(cin, data);
	L.insert(key, data);
} // testInsert()

  //-----------------------------------------------------------
  //                           testDrop
  //-----------------------------------------------------------
void testDrop(LList & L) {
	int key;
	cout << "Enter key:  ";
	cin >> key;
	if (L.drop(key))
		cout << key << " removed\n";
	else
		cout << key << " not found in list\n";
} // testDrop()

  //-----------------------------------------------------------
  //                          testFind
  //-----------------------------------------------------------
void testFind(LList & L) {
	int key;
	cout << "Enter key:  ";
	cin >> key;
	L.findNode(key);
} // testFind()

  //-----------------------------------------------------------
  //                            main()
  //-----------------------------------------------------------
int main() {
	{ // extra block included to view destruction of L
		LList L;
		char action = ' ';
		while (action != 'X') {
			action = askAction();
			switch (action) {
			case 'I': testInsert(L); break;
			case 'D': testDrop(L);   break;
			case 'F': testFind(L);   break;
			case 'P': L.print();     break;
			case 'S': L.sort(); cout << "Sorted\n";  break;
			case 'X': cout << "Exiting...\n"; break;
			default:  cout << "Invalid option\n";
			}
		}
	} // L will be destoyed upon exit of this block
	system("pause");
	return 0;
} // main()