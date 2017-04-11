//
//  FileController.hpp
//  MegaData
//
//  Created by Beverly, Noah on 3/29/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef FileControlller_h
#define FileControlller_h

#include "../Model/DoubleList.hpp" //Default Structure
#include "../Model/FoodItem.hpp" //Datatypes
#include "../Model/Meme.hpp"
#include "../Model/CrimeData.hpp"
#include <string> //String Type
#include <fstream> //file operations
#include <iostream>  //console access
#include <sstream> //String as stream

usinng namespace std; //keyword support

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
public:
    DoubleList<FoodItem> readFoodItemDataFromFileAsList(string filename);
    void writeFoodItemDataStatistics(DoubleList<FoodItem> source, string filename);
};
#endif /* FileControlller_h */
