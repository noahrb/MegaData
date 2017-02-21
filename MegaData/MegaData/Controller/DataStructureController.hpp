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
#include <string>
using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testNodes();
    
public:
    DataStructureController();
    void start();
    void testAdvancedFeatures();
};
#endif /* DataStructureController_hpp */
