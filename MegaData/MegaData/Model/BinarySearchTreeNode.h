//
//  BinarySearchTreeNode.h
//  MegaData
//
//  Created by Beverly, Noah on 4/11/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef BinarySearchTreeNode_h
#define BinarySearchTreeNode_h





public:
BinarySearchTreeNode();
BinarySearchTreeNode(Type data);

BinarySearchTreeNode<Type> * getRootPointer();
BinarySearchTreeNode<Type> * getLeftChild();
BinarySearchTreeNode<Type> * getRightChild();

void setRootPointer(BinarySearchTreeNode<Type> * root);
void setLeftChild(BinarySearchTreeNode<Type> * left);
void setRightChild(BinarySearchTreeNode<Type> * right);
];

template <class Type>
BinarySearchTreeNode<Type> * 

#endif /* BinarySearchTreeNode_h */
