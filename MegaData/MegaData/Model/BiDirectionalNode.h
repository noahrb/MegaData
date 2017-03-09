//
//  BiDirectionalNode.h
//  MegaData
//
//  Created by Beverly, Noah on 2/27/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    BiDirectionalNode<Type> * previous;
    BiDirectionalNode<Type> * next;
    Type data;
public:
    BiDirectinoalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous,
                      BiDirectionalNode<Type> * next);
    
}
template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node()
{
    
}

BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>(data)

#endif /* BiDirectionalNode_h */
