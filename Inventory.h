#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


class Node {
public:
	std::string Name;
	std::string Version;
	int Quantity;
	double Price;
	int posInList;
	Node* right, *left;
	Node();
	Node(std::string name);
	Node(std::string name, std::string version, int quantity, double price);
	Node(int quantity) {
		this->Quantity = quantity;
	}


};
class BST {
private:
	Node* root;
public:
	std::ifstream input;
	std::ofstream output;
	int sizeOfList;
	BST();
	void insert(Node* insertNode);
	void  search(int);
	void inorderTraversal(Node* orderNode);
	int leavesCount(Node* root);
	Node* getRoot();
	Node* deleteNode(int value, Node* deleteRoot);

	bool isLeaf(Node* node);
	Node* findMin(Node* node);
	void preOrderTraversal(Node* preOrderNode);
	void postOrderTraversal(Node* postOrderNode);
	void writeToFile();
	void readFile();
	void PromptDataEntry();
	int numOfLines();
	void ProgramOpen();
	void inorderTraversalPrint(Node* orderNode);
	void updateNode();
	void cleanUp();
	void getStats();
};
#endif //SOFTWARESTOREV3_0_INVENTORY_H
