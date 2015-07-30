#include "BTNode.h"

BTNode::BTNode(void) :
	value(0),
	left(NULL),
	right(NULL)
{
}

BTNode::BTNode(int value, BTNode* left, BTNode* right) :
value(value),
	left(left),
	right(right)
{
}

BTNode::~BTNode(void)
{
	if (left != NULL)
		delete left;

	if (right != NULL)
		delete right;
}

void BTNode::setValue(int value)
{
	this->value = value;
}

int BTNode::getValue(void) const
{
	return this->value;
}

void BTNode::setLeftNode(BTNode* left)
{
	this->left = left;
}

BTNode* BTNode::getLeftNode(void) const
{
	return left;
}

void BTNode::setRightNode(BTNode* right)
{
	this->right = right;
}

BTNode* BTNode::getRightNode(void) const
{
	return right;
}