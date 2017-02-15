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
void Array<Type> :: setAtIndex(int index, Type Data)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
}

template < class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index > 0 && index < size);
    Type value;
    Node<Type>* current = front;
    for(int position = 0; index < inde; position++;
        {
            current = current->getNodePointer();
        }
        
        value = current ->getNodeData();
    
        return value;
}

template <class Type>
Type Array<Type> :: getSize()
{
            return size;
}
#endif /* Array_h */
