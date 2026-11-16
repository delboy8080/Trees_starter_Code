#pragma once
#include "Tree.h"

template <class T>
class TreeIterator
{
public:	
	Tree<T> *node;
	DListIterator<Tree<T>*> childIter;

	TreeIterator(Tree<T>* root);
	void resetIterator();
	void root();
	void up();
	void down();
	void childBack();
	void childForth();
	void childStart();
	void childEnd();
	void appendChild(T item);
	void prependChild(T item);
	void insertChildBefore(T item);
	void insertChildAfter(T item);
	void removeChild();
	bool childValid();
	T childItem();
	T item();
};
template <class T>
TreeIterator<T>::TreeIterator(Tree<T>* root)
{
	node = root;
	resetIterator();
}

template <class T>
void TreeIterator<T>::resetIterator()
{
	if (node == nullptr)
	{
		childIter = nullptr;
	}
	else
	{
		childIter = node->children->getIterator();
	}
}

template <class T>
void TreeIterator<T>::root()
{
	if (node->parent != nullptr)
	{
		node = node->parent;
		root();
	}
	else
	{
		resetIterator();
	}
}

template <class T>
void TreeIterator<T>::up()
{
	if (node->parent != nullptr)
	{
		node = node->parent;
		
	}
	resetIterator();
}

template <class T>
void TreeIterator<T>::down()
{
	if (childIter.isValid())
	{
		node = childIter.item();
		resetIterator();
	}

}

template <class T>
void TreeIterator<T>::childBack()
{
	childIter--;
}

template <class T>
void TreeIterator<T>::childForth()
{
	childIter++;
}

template <class T>
void TreeIterator<T>::childStart()
{
	childIter.start();
}

template <class T>
void TreeIterator<T>::childEnd()
{
	childIter.end();
}

template <class T>
void TreeIterator<T>::appendChild(T item)
{
	Tree<T>* newTree = new Tree<T>(item);
	newTree->parent = node;
	node->children->append(newTree);
	resetIterator();


}

template <class T>
void TreeIterator<T>::prependChild(T item)
{
	Tree<T>* newTree = new Tree<T>(item);
	newTree->parent = node;
	node->children->prepend(newTree);
	resetIterator();
}

template <class T>
void TreeIterator<T>::insertChildBefore(T item)
{
	Tree<T>* newTree = new Tree<T>(item);
	newTree->parent = node;
	node->children->insert(childIter, newTree);
		
	
}

template <class T>
void TreeIterator<T>::insertChildAfter(T item)
{
	Tree<T>* newTree = new Tree<T>(item);
	newTree->parent = node;
	childIter++;
	node->children->insert(childIter, newTree);
	childIter--;
	childIter--;
	

}

template <class T>
void TreeIterator<T>::removeChild()
{
	node->children->remove(childIter);
	
}

template <class T>
bool TreeIterator<T>::childValid()
{
	return childIter.isValid();
}

template <class T>
T TreeIterator<T>::childItem()
{
	return childIter->node->data;
}

template <class T>
T TreeIterator<T>::item()
{
	return node->data;
}