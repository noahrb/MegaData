//
//  FileController.cpp
//  MegaData
//
//  Created by Beverly, Noah on 3/29/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#include "FileController.hpp"




if (rowCount != 0)
{
    cost = stod(tempCost);
    calories = stoi(tempCalorie);
    isDelish = stoi(tempTasty);
    
    FoodItem temp(title);
    temp.setCost(cost);
    temp.setCalories(calories);
    temp.setDelicious(isDelish);
    dataSource.add(temp);
}
