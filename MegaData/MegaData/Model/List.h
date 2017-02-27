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
    Node<Type>* end;
public:
    List <Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    void addEnd(Type value);
    Type getFromIndex(int index);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    bool contains(Type value);
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
    assert(index >= 0 && index < size);
    Type removedData;
    
    Node<Type> * current = front;
    
    for (int spot = 0; spot < index; spot++)
    {
        current = current ->getNodePointer();
    }
    
    removedData = current->getNodeData();
    current->setNodeData(data);
    
    return removedData;
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type information;
    
    Node<Type> * current = front;
    for (int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    information = current->getNodeData();
    
    return information;
}

template <class Type>
Type List<Type> :: remove(int index)
{
        assert(index >= 0 && index < size);
        Type removed;
        
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        Node<Type> * toBeRemoved = nullptr;
        
        if(index == 0)
        {
            toBeRemoved = front;
            this->front = front->getNodePointer();
        }
        else if(index == size - 1)
        {
            for (int spot = 0; spot < index; spot++)
            {
                previous = current;
                current = current->getNodePointer();
            }
            
            toBeRemoved = current;
            previous->setNodePointer(nullptr);
            this->end = previous;
        }
    else
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNodePointer();
        previous->setNodePointer(current);
        
    }
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    size--;
    return removed;
}

template <class Type>
bool List<Type> :: contains(Type findMe)
{
    bool isInList = false;
    Node<Type> * current = front;
    
    for (int index = 0; index < size; index++)
    {
        if (current->getNodeData == findMe)
        {
            isInList = true;
            return isInList;
        }
    }
}
#endif /* List_h */
