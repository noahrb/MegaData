//
//  DoubleList.h
//  MegaData
//
//  Created by Beverly, Noah on 3/9/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h


template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = take->getFront();
    for(int spot = 0; spot < index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp = nodeToTakeOut->getNodeData();
    
    BiDirectionalNode<Type>  * prev = nodeToTakeOut->getPreviousPointer();
    BiDirectionalNode<Type> * next  = nodeToTakeOut->getNextPointer();
    
    prev->setNextPointer(next);
    next->setPreviousPointer(prev);
    
    delete nodeToTakeOut;
    
    this->setSize(this->getSize() - 1);
    return derp;
}

template <class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
    assert(inddex>= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}
#endif /* DoubleList_h */
