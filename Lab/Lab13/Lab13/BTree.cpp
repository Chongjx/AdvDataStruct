#include "BTree.h"

BTree::BTree(void) :
	count(0),
	root(NULL),
	current(NULL),
	prev(NULL),
	newNode(NULL)
{
}

BTree::~BTree(void)
{
	if (newNode)
		delete newNode;
}

void BTree::setRoot(BTNode* root)
{
	this->root = root;
}

void BTree::setCurrent(BTNode* current)
{
	this->current = current;
}

void BTree::setPrev(BTNode* prev)
{
	this->prev = prev;
}

BTNode* BTree::getRoot(void) const
{
	return this->root;
}

BTNode* BTree::getCurrent(void) const
{
	return this->current;
}

BTNode* BTree::getPrev(void) const
{
	return this->prev;
}

int BTree::getCount(void) const
{
	return this->count;
}

void BTree::add(int value)
{
	newNode = new BTNode;
	newNode->setValue(value);

	// if the value is the first value entered
	if (root == NULL)
	{
		root = newNode;
	}

	// there is alr a root
	else
	{
		current = root;
		bool allocated = false;
		bool goLeft = false;

		// transverse down the tree until the node is allocated
		while (!allocated)
		{
			prev = current;
			// value smaller than or equal to current, go left
			if (newNode->getValue() <= current->getValue())
			{
				current = current->getLeftNode();
				goLeft = true;
			}

			// value larger than current, go right
			else
			{
				current = current->getRightNode();
				goLeft = false;
			}

			// if the node contains nothing, allocate the new node there
			if (current == NULL)
			{
				if (goLeft)
					prev->setLeftNode(newNode);

				else
					prev->setRightNode(newNode);

				allocated = true;
				++count;
			}
		}
	}
}

void BTree::printFromRoot(BTNode *node)
{
	// continue only if node not empty
	if (node != NULL)
	{
		// recursive call to find a leaf
		if (node->getLeftNode())
		{
			// assign current child as 'root'
			printFromRoot(node->getLeftNode());
		}

		cout << node->getValue() << " ";

		if (node->getRightNode())
		{
			// assign current child as 'root'
			printFromRoot(node->getRightNode());
		}
	}
}

void BTree::print(void)
{
	cout << endl;
	printFromRoot(root);
	cout << endl;
}