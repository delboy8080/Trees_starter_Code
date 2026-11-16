// Trees.cpp : Defines the entry point for the console application.
//
#include "Tree.h"
#include "TreeIterator.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;
/*
	The indented parenthetic representation of a tre
*/
void displayTree(TreeIterator<string> iter, string indent)
{
	cout << indent << iter.item();
	if (iter.childValid())
	{
		cout << "(";
	}
	cout << endl;
	while (iter.childValid())
	{
		TreeIterator<string> copy(iter);
		copy.down();
		displayTree(copy, indent + "\t");
		iter.childForth();
	}
	iter.childStart();
	if (iter.childValid())
	{
		cout <<indent<< ")" << endl;;
	}
}
/*
	Print using a Depth First Search
*/
void printDFS(TreeIterator<string> iter)
{
	
}
/*
	Print using a Breadth first Search
*/
void printBFS(Tree<string> tree)
{
	

}
/*
	Code to test for question 1
*/
void question1()
{
	Tree<string> root("Sales");
	TreeIterator<string> iter(&root);
	iter.appendChild("Domestic");
	iter.appendChild("International");
	iter.childForth();
	iter.down();
	iter.appendChild("Canada");
	iter.appendChild("S. America");
	iter.appendChild("Overseas");
	iter.childEnd();
	iter.down();
	iter.appendChild("Africa");
	iter.appendChild("Aisa");
	iter.appendChild("Europe");
	iter.appendChild("Australia");
	iter.root();
	displayTree(iter, "");

}
/*
	Code to test question 2 & 3.
*/
void question2()
{
	
}

int main()
{
	
	question1();
    return 0;
}

