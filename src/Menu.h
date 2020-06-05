#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"
#include "clearScreen.h"
using std::cout;

void load(BST& tree) {
    std::ifstream inFile("tree.txt");

    int i = 0;
    while (!inFile.is_open()) {
	if (i > 2) {
	    cout << "File failed to open, probably not found, idk\n";
	    return;
	}
	cout << "File didn't open, give me just a bit\n";
	inFile.open("tree.txt", std::ios::in);
	++i;
    }

    if (!tree.isEmpty()) tree.clear();
    int value;
    while (inFile >> value)
	tree.rAdd(value);
    inFile.close();
}

void saveTraversals(BST& tree) {
    std::ofstream outFile("output.txt");

    while (!outFile.is_open()) {
	std::cout << "File didn't open, give me just a bit\n";
	outFile.open("output", std::ios::out);
    }
    outFile << "Pre-order (NLR): " << tree.rPreOrderTraversal() << "\n";
    outFile << "In-order (LNR): " << tree.rInOrderTraversal() << "\n";
    outFile << "Post-order (LRN): " << tree.rPostOrderTraversal() << "\n";
    outFile << "Breadth-first: " << tree.breadthTraversal() << "\n";
    outFile.close();
}

void choice(const int &c, BST &tree) {
    clearScreen();

    switch (c) {
	case 0:
	{
	    if (tree.isEmpty())
		std::cout << "Tree is empty\n\n";
	    else {
		cout << "Pre-order (NLR): " << tree.rPreOrderTraversal() << "\n";
		cout << "In-order (LNR): " << tree.rInOrderTraversal() << "\n";
		cout << "Post-order (LRN): " << tree.rPostOrderTraversal() << "\n";
		cout << "Breadth-first: " << tree.breadthTraversal() << "\n\n";
	    }
	    break;
	}

	case 1:
	{
	    int value;
	    cout << "Enter value: ";
	    std::cin >> value;

	    int result = tree.rAdd(value);
	    switch (result) {
		case 1:
		{
		    cout << "Value already exists\n\n";
		    break;
		}
		case -1:
		{
		    cout << "Something went wrong, couldn't add\n\n";
		    break;
		}

		default:
		{
		    cout << "Value pushed\n\n";
		    break;
		}
	    }
	    break;
	}

	case 2:
	{
	    int value;
	    cout << "Enter value: ";
	    std::cin >> value;

	    int result = tree.add(value);
	    switch (result) {
		case 1:
		{
		    cout << "Value already exists\n\n";
		    break;
		}

		default:
		{
		    cout << "Value pushed\n\n";
		    break;
		}
	    }
	    break;
	}

	case 3:
	{
	    if (tree.isEmpty())
		cout << "Tree is empty\n\n";
	    else {
		int value;
		cout << "Enter value: ";
		std::cin >> value;

		int result = tree.rDeleteNode(value);
		switch (result) {
		    case 1:
		    {
			cout << "Value already exists\n\n";
			break;
		    }

		    default:
		    {
			cout << "Value deleted\n\n";
			break;
		    }
		}
	    }
	    break;
	}

	case 4:
	{
	    if (tree.isEmpty())
		cout << "Tree is empty\n\n";
	    else {
		int value;
		cout << "Enter value: ";
		std::cin >> value;

		Node* result = tree.rFind(value);
		if (!result)
		    cout << "Value not found\n\n";
		else
		    cout << "Value " << value << " found\n\n";
	    }
	    break;
	}

	case 5:
	{
	    if (tree.isEmpty())
		cout << "Tree is empty\n\n";
	    else {
		int value;
		cout << "Enter value: ";
		std::cin >> value;

		Node* result = tree.find(value);
		if (!result)
		    cout << "Value not found\n\n";
		else
		    cout << "Value " << value << " found\n\n";
	    }
	    break;
	}

	case 6:
	{
	    if (tree.isEmpty())
		cout << "Tree is empty\n\n";
	    else {
		cout << "Tree height = " << tree.getHeight() << "\n\n";
	    }
	    break;
	}

	case 7:
	{
	    tree.clear();
	    cout << "Tree cleared\n\n";
	    break;
	}

	case 8:
	{
	    if (tree.isEmpty())
		std::cout << "Tree is empty\n";
	    else
		std::cout << "Tree is not empty\n";
	    break;
	}

	case 9:
	{
	    load(tree);
	    cout << "Tree created from tree.txt\n\n";
	    break;
	}

	case 10:
	{
	    saveTraversals(tree);
	    cout << "Traversals saved to output.txt\n\n";
	    break;
	}
    }
}

void menu(BST &tree) {
    short int c;
    while (true) {
	std::cout << "Options:\n\n";
	std::cout << "0. Print all traversals\n";
	std::cout << "1. Add value (recursive)\n";
	std::cout << "2. Add value (non-recursive)\n";
	std::cout << "3. Delete value\n";
	std::cout << "4. Find element by key (recursive)\n";
	std::cout << "5. Find element by key (non-recursive)\n";
	std::cout << "6. Get height of tree\n";
	std::cout << "7. Clear tree\n";
	std::cout << "8. Check if empty\n";
	std::cout << "9. Load from tree.txt\n";
	std::cout << "10. Save traversals to output.txt\n";

	std::cin >> c;

	choice(c, tree);
    }
}

