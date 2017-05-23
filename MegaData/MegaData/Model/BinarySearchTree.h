//
//  BinarySearchTree.h
//  MegaData
//
//  Created by Beverly, Noah on 4/11/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include "BinarySearchTreeNode.h"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    void printToFile();
    
    void demoTraversalSteps(BinarySearchTreeNode<Type> * node);
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
        cout << "Node Contents: " << preStart->getNodeData() << endl;
        preOrderTraversal(preStart->getLeftChild());
        preOrderTraversal(preStart->getRightChild());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeftChild());
        postOrderTraversal(postStart->getRightChild());
        cout << "Node Contents: " << postStart->getNodeData() << endl;
    }
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    int count = 1;
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        count += calculateSize(start->getLeftChild());
        count += calculateSize(start->getRightChild());
        return count;
    }
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current ->getNodeData())
            {
                return true;
            }
            else if (itemToFind < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert > current-> getNodeData())
            {
                current = current->getRightChild();
            }
            else
            {
                cerr << "ITEM ALREADY EXISTS CLOSING" << endl;
                delete insertMe;
                return;

            }
        }
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
}
                
template <class Type>
void BinarySearchTree<Type> ::removeNode(BinarySearchTreeNode<Type> *  removeMe)
{
    BinarySearchTreeNode<Type> * current;
    BinarySearchTreeNode<Type> * previous;
    BinarySearchTreeNode<Type> * temp;

    previous = removeMe->getRootPointer();
    //no child
    if(removeMe->getRightChild() == nullptr && removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;

        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);

        }
        else if(previous != nullptr && removeMe ->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }

        delete temp;
    }
    //left child
    else if(removeMe->getRightChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChild();

        if(previous != nullptr && temp->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }

        removeMe->setRootPointer(previous);

        delete temp;
    }
    //right child
    else if(removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightChild();

        if(previous != nullptr && temp->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }

        removeMe->setRootPointer(previous);

        delete temp;
    }
    //both children
    else
    {
        current = removeMe->getLeftChild();
        previous = nullptr;

        while(current->getRightChild() != nullptr)
        {
            previous = current;
            current = current->getRightChild();
        }

        removeMe->setNodeData(current->getNodeData());

        if(previous == nullptr)
        {
            removeMe->setLeftChild(current->getLeftChild());
            if(current->getLeftChild() != nullptr)
            {
            current->getLeftChild()->setRootPointer(removeMe);
            }
        }
        else
        {
            if(current->getLeftChild() != nullptr)
            {
            previous->setRightChild(current->getLeftChild());
            current->getLeftChild()->setRootPointer(previous);
            }
        }

        delete current;
    }
    if(removeMe->getRootPointer() == nullptr || removeMe->getRootPointer() == nullptr)
    {
        setRoot(removeMe);
    }

}

#endif /* BinarySearchTree_h */
