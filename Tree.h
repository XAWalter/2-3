#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
public:
  Tree( );
 // ~Tree( );
  void insert(const string &);
  void preOrder( ) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void remove(const string &);
  bool search (const string &) const;

private:
	Node* top;
	void insert(Node*, const string &);
	Node* search(Node*, const string &);
	void split(Node*, const string &);
    
};

#endif
