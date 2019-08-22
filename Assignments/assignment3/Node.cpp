/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 * 
 * 	Edited in: July 27 2019
 * 		Editor: Takunda Mwinjilo (301344066)
 */

#include "Node.h"

Node::Node(string surname, char initial, int balance)
{
    Customer c(surname, initial, balance);
    customer = c;
    left = NULL;
    right = NULL;
}

Node::Node(const Node* node)
{
    Customer c(node->customer.getLastName(),node->customer.getInitial(),node->customer.getBalance());
    customer = c;
    left = NULL;
    right = NULL;
}