//
//  List.h
//  MegaData
//
//  Created by Beverly, Noah on 2/21/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef List_h
#define List_h
#include <iostream>
#include "../Model/Node.h"
#include "../Controller/DataStructureController.hpp"
#include <assert.h>

using namespace std;

template <class Type>
class List
{
private:
    int size;
    Node<Type>* front;
public:
    List <Type>();
    
    //Destructor
    ~List<Type>();
    //CopyConstructor
    List<Type>(const List<Type> & source);
    //HelperMethods
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    bool contains(Type data);
    int getSize() const;
    Node<Type>* getFront() const;
};

template <class Type>
Node<Type> * List<Type> :: getEnd() const
{}

template <class Type>
void List<Type> :: addFront(Type value)
{
    if(size == 0)
    {
        Node<Type> * first = new Node<Type>(value);
        this->front = first;
        this->end = first;
    }
    else {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNodePointer(front);
        //or
        //Node<Type> * newFirst = new Node<Type>(value, front);
        this->front = newFirst;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNodePointer(added);
        this->end = added;
    }
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >=0 && index <= size);
    if(size == 0)
    {
        addFront(value);
    }
    else if(index == size)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        previous->setNodePointer(insertedNode);
        insertedNode->setNodePointer(current);
    }
    size++;
}

template <class Type>
Type List<Type> :: setAtIndex(int index, Type data)
{
    
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    
}

template <class Type>
Type List<Type> :: remove(int index)
{
    
}

template <class Type>
bool List<Type> :: contains(Type findMe)
{
    
}
#endif /* List_h */
