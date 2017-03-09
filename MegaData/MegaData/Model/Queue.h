//
//  Queue.h
//  MegaData
//
//  Created by Beverly, Noah on 3/7/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template<class Type>
class Queue : public DoublyLinkedList<Type>
{
private:
public:
    Queue();
    ~Queue();
    void add (Type data);
    Type remove(int index);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{
    
}
#endif /* Queue_h */
