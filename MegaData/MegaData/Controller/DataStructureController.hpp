//
//  DataStructureController.hpp
//  MegaData
//
//  Created by Beverly, Noah on 2/8/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp
#include "../Model/Node.h"
#include "../Model/Array.h"
#include "../Model/FoodItem.hpp"
#include "../Model/DoubleList.h"
#include "../Model/Stack.h"
#include "../Model/Queue.h"
#include "../Model/CircularList.h"
#include "../Model/Timerhpp"
#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    //void testNodes();
    void testAdvancedFeatues();
    void testIntStack();
    void testFoodQueue();
    
public:
    DataStructureController();
    void start();
    void testAdvancedFeatures();
};
#endif /* DataStructureController_hpp */
