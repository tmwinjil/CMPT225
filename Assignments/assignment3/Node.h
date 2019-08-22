/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 * 
 * 	Edited in: July 27 2019
 * 		Editor: Takunda Mwinjilo (301344066)
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"
using namespace std;

class Node {
public:
    Customer customer; //The Node key
    Node* left;
    Node* right;
    Node* parent;


    Node(string, char, int);
    Node(const Node* node);//Copy Constructor

};

#endif /* NODE_H_ */
