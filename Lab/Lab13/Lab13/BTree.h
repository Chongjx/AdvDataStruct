#ifndef B_TREE_H
#define B_TREE_H

#include "BTNode.h"

using std::cin;
using std::cout;
using std::endl;

class BTree
{
private:
	BTNode *root, *current, *prev, *newNode;
	int count;
public:
	BTree(void);
	~BTree(void);

	void setRoot(BTNode* root);
	void setCurrent(BTNode* current);
	void setPrev(BTNode* prev);

	BTNode* getRoot(void) const;
	BTNode* getCurrent(void) const;
	BTNode* getPrev(void) const;

	int getCount(void) const;

	void add(int value);
	void printFromRoot(BTNode *node);
	void print(void);
};

#endif