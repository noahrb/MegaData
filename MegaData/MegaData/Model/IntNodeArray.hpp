//
//  IntNodeArray.hpp
//  MegaData
//
//  Created by Beverly, Noah on 2/8/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef IntNodeArray_hpp
#define IntNodeArray_hpp

class IntNodeArray
{
private:
    IntNode * front;
    int size;
    
public:
    IntNodeArray(int size);
    void setAtIndex(int index, int value);
    int getFromIndex(int index);
    int getSize();
};

#endif /* IntArray_hpp */
