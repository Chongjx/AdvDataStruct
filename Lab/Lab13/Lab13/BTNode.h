#ifndef BT_NODE_H
#define BT_NODE_H

#include <iostream>

class BTNode
{
private:
	int value;
	BTNode* left;
	BTNode* right;
public:
	BTNode(void);
	BTNode(int value, BTNode* left, BTNode* right);
	~BTNode(void);

	void setValue(int value);
	int getValue(void) const;

	void setLeftNode(BTNode* left);
	BTNode* getLeftNode(void) const;

	void setRightNode(BTNode* right);
	BTNode* getRightNode(void) const;
};

#endif