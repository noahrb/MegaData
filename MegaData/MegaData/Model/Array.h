//
//  Array.h
//  MegaData
//
//  Created by Beverly, Noah on 2/15/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef Array_h
#define Array_h

template <class Type>
class Array
{
private:
    Node<Type> front;
    int size;
public:
    Array();
    Array(int size);
    
    int getSize();
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index)
    
};

/*
 Implementation Section
 */

template <class Type>
Node<Type> :: Node()
{
    //Explicitly DO NOT instantiate the nodeData data member
    this->nodePointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nodePointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type nodeData, Node<Type> * nodePointer)
{
    this->nodeData = nodeData;
    this->nodePointer = nodePointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type data)
{
    this->nodeData = data;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return this->nodeData;
}

template <class Type>
Node<Type> * Node<Type> :: getNodePointer()
{
    return this->nodePointer;
}

#endif /* Node_h */

#endif /* Array_h */
