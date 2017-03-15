//
//  FoodItem.hpp
//  MegaData
//
//  Created by Beverly, Noah on 3/13/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef FoodItem_hpp
#define FoodItem_hpp

#include <string>
using namespace std;

class FoodItem
{
private:
    int calories;
    string foodName;
    double cost;
    bool delicious;
public:
    FoodItem();
    FoodItem(string name);
    
    int getCalories();
    string getFoodName();
    double getCost();
    bool isDelicous();
    
    void setCalories(int calories);
    void setFoodName(string name);
    void setCost(double cost);
    void setDelicious(bool delicous);
};

#endif /* FoodItem_hpp */
