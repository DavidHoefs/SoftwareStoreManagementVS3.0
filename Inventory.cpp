#include "Inventory.h"


Node::Node() {
	this->Name = "";
	this->Version = "";
	this->Quantity = 0;
	this->Price = 0;
	right = 0;
	left = 0;
	posInList++;
}


Node::Node(std::string name) {
	this->Name = name;
	
}
Node::Node(std::string name, std::string version, int quantity, double price) {
	this->Name = name;
	this->Version = version;
	this->Quantity = quantity;
	this->Price = price;
	right = 0;
	left = 0;
	posInList++;
}
BST::BST() {
	this->root = nullptr;
}
void BST::insert(Node* insertNode) {

	if (!this->root) {
		this->root = insertNode;
	}
	else {
		Node*  temp;
		temp = this->root;
		while (true) {
			if (insertNode->Name < temp->Name) {
				if (temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = insertNode;
					break;
				}
			}
			else if (insertNode->Name > temp->Name) {
				if (temp->right != NULL) {
					temp = temp->right;
				}
				else {
					temp->right = insertNode;
					break;
				}
			}
			else {
				std::cout << "No Duplicates Allowed!" << std::endl;
				break;
			}
		}
		
	}
}
void BST::inorderTraversalPrint(Node* orderNode) {
	if (orderNode == NULL) {
		return;
	}
	// otherwise, recursively call inorderTraversal() function on left and right sides until you reach the end

	inorderTraversalPrint(orderNode->left);
	std::cout << orderNode->Name << "\t\t" << orderNode->Version << "\t" << orderNode->Quantity << "\t" << orderNode->Price << std::endl;

	

	inorderTraversalPrint(orderNode->right);


}

void BST::updateNode()
{
	std::string name;
	int quantity;
	std::cout << "Enter Name of product to update: " << std::endl;
	std::cin >> name;
	std::cout << "Enter new Quantity: " << std::endl;
	std::cin >> quantity;
	Node* searchNode = new Node(name);
	if (!this->root) {
		std::cout << "No Data" << std::endl;
	}
	if (name == root->Name) {
		root->Quantity = quantity;
		
	}
	else {
		Node* temp = root;
		while (true) {
			if (name < temp->Name) {
				searchNode = temp->left;
				temp = temp->left;
			}
			if (searchNode == NULL) {
				std::cout << "Product does not exist in inventory" << std::endl;
				
				break;
			}
			if (name == searchNode->Name) {
				searchNode->Quantity = quantity;
				break;
			}
		}
	}
}

void BST::inorderTraversal(Node* orderNode) {
	// if there are no values, return
	if (orderNode == NULL) {
		return;
	}
	// otherwise, recursively call inorderTraversal() function on left and right sides until you reach the end

	inorderTraversal(orderNode->left);
	std::cout << orderNode->Name << "\t" << orderNode->Version << "\t" << orderNode->Quantity << "\t" << orderNode->Price << std::endl;
	
	output << orderNode->Name << "\t\t" << orderNode->Version << "\t" << orderNode->Quantity << "\t" << orderNode->Price << std::endl;

	inorderTraversal(orderNode->right);


}
void BST::writeToFile() {
	///std::ofstream output;
	output.open("C:\\Users\\hoefs\\Desktop\\testsoftware.txt", std::ios_base::out | std::ios_base::trunc);
	if (output.is_open()) {
		
		///PromptDataEntry();
		inorderTraversal(root);
		output.close();
	}
	return;
}
void BST::PromptDataEntry() {
	std::string name;
	std::string version;
	int quantity;
	double price;
	int addToSize;
	

	std::cout << "Enter number of products to add to list\n";
	std::cin >> addToSize;
	sizeOfList += addToSize;
	
	input.seekg(0, std::ios_base::end);
	if (input.tellg() == 0) {
		output << "Name:" << "\t\t" << "Ver." << "\t" << "Quan." << "\t" << "Price:\n";
		output << "-------------------------------------------------------------------------\n";
		
	}
		
	
	
	////output.open("testsoftware.txt", std::ios_base::in);

	for (int i = 0; i < addToSize; i++) {


		std::cout << "Enter Name of Product: \n";
		std::cin >> name;
		std::cout << "Enter Version: \n";
		std::cin >> version;
		std::cout << "Enter Quantity: \n";
		std::cin >> quantity;
		std::cout << "Enter Price: \n";
		std::cin >> price;
		Node* newNode = new Node(name,version,quantity,price);
		

		insert(newNode);
		


	}
	

}
Node* BST::getRoot() {
	return this->root;
}
void BST::readFile() {
	std::string name;
	std::string version;
		int quantity;
	double price;
	int i = 0;
	std::string stillData;
	sizeOfList = numOfLines();
	input.open("C:\\users\\hoefs\\Desktop\\testsoftware.txt", std::ios_base::in);


	///std::cout << "read test---" << std::endl;
	input.seekg(0, std::ios_base::end);
	if (input.tellg() == 0) {
		PromptDataEntry();
		return;
	}
	else {


		///input >> sizeOfList;
		///std::cout << "Items in list: " << sizeOfList << std::endl;
		input.seekg(0);
		while (input) {



			if (i == sizeOfList) {
				break;
			}
			input >> name >> version >> quantity >> price;
			///std::cout << name << " " << version << " " << quantity << " " << price << std::endl;
			Node* tempNode = new Node(name, version, quantity, price);
			insert(tempNode);
			i++;


		}

	}
	
	input.close();
	
}
void BST::preOrderTraversal(Node* preOrderNode) {
	if (preOrderNode) {
		// Print root, print left, print right
		std::cout << preOrderNode->Name << " " << preOrderNode->Version << " " << preOrderNode->Quantity << " " << preOrderNode ->Price << std::endl;
		preOrderTraversal(preOrderNode->left);
		preOrderTraversal(preOrderNode->right);
	}
}
int BST::numOfLines() {
	int numLines = 0;
	std::string line;
	input.open("C:\\users\\hoefs\\desktop\\testsoftware.txt");
	while (std::getline(input, line)) {
		++numLines;
		///std::cout << "Number of lines in text file: " << numLines << std::endl;
	}
	input.close();
	return numLines;
}
void BST::ProgramOpen() {
	int choice;
	while (true) {

		std::cout << "*--------------------------------*" << std::endl;
		std::cout << "*								   *" << std::endl;
		std::cout << "*Software Store Management System*" << std::endl;
		std::cout << "*                                *" << std::endl;
		std::cout << "*--------------------------------*" << std::endl;
		std::cout << "Enter 1 to view current inventory: " << std::endl;
		std::cout << "Enter 2 to add product to list: " << std::endl;
		std::cout << "Enter 3 to update info of current product: " << std::endl;
		std::cout << "Enter 4 to end: " << std::endl;
		std::cout << "Enter 5 to view inventory stats: " << std::endl;
		
		std::cin >> choice;

		switch (choice) {
		case 1:
			inorderTraversalPrint(root);
			break;
		case 2:
			PromptDataEntry();
			break;
		case 3:
			updateNode();
			
			break;
		case 4:
			writeToFile();
			return;

		case 5:

		}

		
	}
}
void BST::cleanUp() {
	
	
}
void BST::getStats() {

}
