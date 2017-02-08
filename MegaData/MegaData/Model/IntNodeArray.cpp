//
//  IntNodeArray.cpp
//  MegaData
//
//  Created by Beverly, Noah on 2/8/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#include "IntNodeArray.hpp"
#include <assert.h>

IntNodeArray :: IntNodeArray(int size)
{
    assert(size > 0);
    
    this->size = size;
    this->front = new IntNode();
    
    for(int index = 0; index < size; index++)
    {
        IntNode * current = new IntNode();
        current->setNodePointer();
        front = current;
    }
    
}

void IntNodeArray :: getFromIndex(int index)
{
    assert(index >= 0 && index < size)
    int value = 0;
    
    IntNode * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    return value;
}
