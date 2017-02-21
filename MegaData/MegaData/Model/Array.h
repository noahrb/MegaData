//
//  Array.h
//  MegaData
//
//  Created by Beverly, Noah on 2/15/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef Array_h
#define Array_h
#include <iostream>
#include "../Model/Node.h"
#include "../Controller/DataStructureController.hpp"
#include <assert.h>

using namespace std;
template <class Type>
class Array
{
private:
    Node<Type> *front;
    int size;
public:
    Array();
    Array(int size);
    
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    
    //Helper Methods
    int getSize() const;
    Node<Type> * getFront() const;
    
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    
};

/*
 Implementation Section
 */

template <class Type>
Array<Type> :: Array()
{
    //Explicitly DO NOT instantiate the nodeData data member

}

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    this->front = new Node<Type>();
    
    for (int index = 1; index < size; index++)
    {
        Node<Type> * current = new Node<Type>();
        current->setNodePointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(data);
}

template < class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index > 0 && index < size);
    Type value;
    Node<Type>* current = front;
    for(int position = 0; index < index; position++);
        {
            current = current->getNodePointer();
        }
        
        value = current ->getNodeData();
    
        return value;
}

template <class Type>
int Array<Type> :: getSize() const
{
            return size;
}
        
/*
 The role of the destructor is to de-allocate all memory called by the use of the 'new' keyword.
 This is to prevent problems such as memory leaks. The destructor is NEVER called by the programmer; rather,
 the destrcutor is called when either the variable goes out of scope, or the pointer to the variable is deleted.
 The count and cout statements are temporary and will be deleted.
 */
template <class Type>
Array<Type> :: ~Array()
    {
        int count = size;
        Node<Type> * remove = front;
        while(front != nullptr)
        {
            //move to next node in array
            front = front ->getNodePointer();
            cout << "Moving to the next node. At: " << count << endl;
            //delete the front pointer
            delete remove;
            cout << "Deleting the old front pointer." << endl;
            //Move delete to the new front.
            remove = front;
            cout << "moving to the new front pointer." << endl;
            count--;
            cout << "Front is at: " << front << " count is: " << count << endl;
        }
    }
    
    /* The copy constructor is called when you create a instance of an object by assigning it via the assignment operator (=).
     The default copy constructor only create a shallow copy, so 
     when buliding custom objects you must override the copy constructor C++ unlike java/swift does not support calling another constructor in 
     a constructor.
     */
    template <class Type>
    Array<Type> :: Array(const Array<Type> & toBeCopied)
    {
        this->size = toBeCopied.getSize();
        
        //Build Data Structure
        this->front = new Node<Type>();
        for(int index = 1; index < size; index++)
        {
            Node<Type> * temp = new Node<Type>();
            temp->setNodePointer(front);
            front = temp;
        }
        //Copy values into new array.
        //This could be done at the same time as the bulid step
        //but this is easier to explain.
        Node<Type> * copyTemp = toBeCopied.getFront();
        Node<Type> * updated = this->front;
        for(int index = 0; index < size; index++)
        {
            updated->setNodeData(copyTemp->getNodeData());
            updated = updated->getNodePointer();
            copyTemp = copyTemp->getNodePointer();
        }
    }
    
    /* 
     the const modifier at the end of the method is used to denote that the method does not impact the state of the object.
     */
    template <class Type>
    Node<Type> * Array<Type> :: getFront() const
    {
        return front;
    }
#endif /* Array_h */
