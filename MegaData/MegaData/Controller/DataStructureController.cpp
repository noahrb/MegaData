//
//  DataStructureController.cpp
//  MegaData
//
//  Created by Beverly, Noah on 2/8/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNode.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/Node.h"
#include "../Model/Array.h"
using namespace std;

DataStructureController ::
    DataStructureController()
{
    wordNode = Node<string>("derpy mcderpface");
    numberNode = Node<int>();
}

void DataStructureController:: testNodes()
{
    cout << "The contents of the Node<string>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController :: start
    ()
{
    cout << "Starting the prject" << endl;
    
    cout << "Switching to the array testing" << endl;
    testIntArray();
    cout << "Finished testing" << endl;
}

void DataStructureController:: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match:" << endl;
    cout << words.getFromIndex(0) << " should be the same as "
    << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
}
void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for (int index = 0; index < 4; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot "<< index << endl;
    }
    
    cout << "Testing input" << endl;
    
    for(int index = 0; index < 3; index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot "<< index << endl;
    }
}

void DataStructureController:: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTime();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExectionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTme[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    totalTimer.stopTimer();
    
    cout << "The average speed for the getFromIndex method was : " << averageSlow << " microseconds."
    << endl;
    
    cout << "The average "
}

void DataStructureController:: testFoodQueue()
{
    Queue<FoodItem> tastyFood;
    FoodItem memeFood("toing");
    
    tastyFood.equeue(memeFood);
    FoodItem boring;
    tastyFood.add(boring);
    
    FoodItem removed = tastyFood.dequeue();
    cout << "The item removed from the queue was: " << removed.getFoodName() << " and should be: toing" << endl;
}
