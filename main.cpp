#include "Tree.h"
#include <iostream>

using namespace std;

//void printOrders(Tree *tree) {
//  cout << "Preorder = ";
//  tree->preOrder( );
//  cout << "Inorder = ";
//  tree->inOrder( );
//  cout << "Postorder = ";
//  tree->postOrder( );
//}
//
//int menu() {
//  int choice = 0;
//  cout << endl << "Enter menu choice: ";
//  cout << endl;
//  cout 
//    << "1. Insert" << endl
//    << "2. Remove" << endl
//    << "3. Print" << endl
//    << "4. Search" << endl
//    << "5. Quit" << endl;
//  cin >> choice;
//  
//  // fix buffer just in case non-numeric choice entered
//  // also gets rid of newline character
//  cin.clear();
//  cin.ignore(256, '\n');
//  return choice;
//}

int main( ) {

	Tree tree;

	tree.insert("h");
	tree.insert("a");
	tree.insert("z");
	tree.insert("b");
	tree.insert("p");
	tree.insert("t");
	tree.insert("w");
	tree.insert("c");
	tree.insert("l");
	tree.insert("s");
	tree.insert("d");
	tree.insert("i");
	tree.insert("j");
	tree.insert("k");
	tree.insert("m");
	tree.insert("n");
	tree.insert("o");
	tree.insert("q");
	tree.insert("r");



  //Tree tree;

  //int choice = menu();

  //string entry;
  //
  //while (choice != 5) {
  //  if (choice == 1) {
  //    cout << "Enter movie title to insert: ";
  //    getline(cin, entry);
  //    cout << endl;
  //    
  //    tree.insert(entry);
  //    
  //  } else if (choice == 2) {
  //    cout << "Enter movie title to remove: ";
  //    getline(cin, entry);
  //    cout << endl;
  //    
  //    tree.remove(entry);
  //    
  //  } else if (choice == 3) {
  //    printOrders(&tree);
  //    
  //  } else if (choice == 4) {
  //    cout << "Enter movie title to search for: ";
  //    getline(cin, entry);
  //    cout << endl;
  //    
  //    if (tree.search(entry)) {
  //      cout << "Found" << endl;
  //    } else {
  //      cout << "Not Found" << endl;
  //    }
  //  }

  //  //fix buffer just in case non-numeric choice entered
  //  choice = menu();
  //}
  //
  system("pause");
  return 0;
}
