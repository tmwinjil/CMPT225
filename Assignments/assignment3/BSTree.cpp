/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 * 
 * 	Edited in: July 27 2019
 * 		Editor: Takunda Mwinjilo (301344066)
 */

#include "BSTree.h"


BSTree::BSTree() {
	root = NULL;
}

BSTree::BSTree(const BSTree & rbt)
{
	root = NULL;
	makeTree(rbt.root);
}

BSTree::~BSTree() 
{
	deleteTree(root);
}


bool BSTree::insert(string x, char y, int z) {
	Node* newNode = new Node(x,y,z);
	if (root == NULL) {
		root = newNode;
		return true;
	}
	
	Node* current = root;
	while (1) {
		if (newNode->customer < current->customer) {
			if (current->left == NULL) {
				current->left = newNode;
				newNode->parent = current;
				break;
			}
			else {
				current = current->left;
				continue;
			}
		}
		else if (newNode->customer > current->customer) {
			if (current->right == NULL) {
				current->right = newNode;
				newNode->parent = current;
				break;
			}
			else {
				current = current->right;
				continue;
			}
		}
		else if (newNode->customer == current->customer) {
			current->customer.setBalance(z);
			delete newNode;
			return false;
		}
	}
	return true;
}


bool BSTree::remove(string x, char y)
{
	Node* current = root;
	Node* temp;
	Node** source = &root;
	Customer searchCustomer(x,y,0);
	/* Removal  Cases:
	* 1) Node has no children (simply delete and reduce size by 1)
	* 2) Node has one child (replace the node with that child)
	* 3) Node has 2 children (Replace the node with the next node in in-order traversal)
	* */
	while(current != NULL) {
		if(searchCustomer == current->customer) {
			if(removeExternalNode(current, source)) {
				return true;
			} else {
				temp = leftMostNode(current->right);
				Node* newNode = new Node(temp);
				*source = newNode;
				newNode->left = current->left;
				newNode->right = current->right;
				newNode->parent = current->parent;
				current->left->parent = newNode;
				current->right->parent = newNode;
				
				if (temp->parent != current) {
					removeExternalNode(temp, &(temp->parent->left));
				}else {
					removeExternalNode(temp, &(current->right));
				}
				delete current;
			}
			return true;
		} else if (searchCustomer < current->customer) {
			source = &(current->left);
			current = current->left;
			continue;
		} else {
			source = &(current->right);
			current = current->right;
		}
	}
	return false;
}


bool BSTree::search(string x, char y)
{
	Node* current = root;
	Customer searchCustomer(x,y,0);
	while(current != NULL) {
		if(searchCustomer == current->customer)
			return true;
		else if (searchCustomer < current->customer) {
			current = current->left;
			continue;
		} else {
			current = current->right;
		}
	}
	return false;
}


vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a)
{
	vector<Customer> v;
	Customer min(x,y, 1);
	Customer max(z,a, 1);
	inOrderAdd(root, &v, &min, &max);
	return v;
}


void BSTree::inOrderPrint() 
{
	printTree(root);
}


Node* BSTree::leftMostNode(Node* n)
{
	Node* currentNode = n;
	while(currentNode->left != NULL) {
		currentNode = currentNode->left;
	}
	return currentNode;
}

bool BSTree::removeExternalNode(Node* n, Node** parentLink)
{
	if(n->left == NULL && n->right == NULL) {//No children
		if (n == root) {
			root == NULL;
		} else {
			*parentLink = NULL;
		}
	} //One Child
	else if (n->left == NULL) { 
		n->right->parent = n->parent;
		*parentLink = n->right;
	} else if (n->right == NULL) {
		n->left->parent = n->parent;
		*parentLink = n->left;
	} else {//Node not external
		return false;
	}
	delete n;
	return true;
}

void BSTree::deleteTree(Node* n)
{
	if (n == NULL)
		return;
	deleteTree(n->left);
	deleteTree(n->right);
	delete n;
}

void BSTree::makeTree(Node* n)
{
	if (n == NULL)
		return;
	insert(n->customer.getLastName(), n->customer.getInitial(), n->customer.getBalance());
	makeTree(n->left);
	makeTree(n->right);
}

void BSTree::printTree(Node* n) {
	if (n == NULL)
		return;
	printTree(n->left);
	cout<<n->customer<<endl;
	printTree(n->right);
}

void BSTree::inOrderAdd(Node* n, vector<Customer>* v, Customer* min, Customer* max)
{
	if (n == NULL)
		return;
	inOrderAdd(n->left, v, min, max);
	if (n->customer >= *min && n->customer <= *max)
		v->push_back(n->customer);
	inOrderAdd(n->right, v, min, max);

}