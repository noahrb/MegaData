//
//  Timer.cpp
//  MegaData
//
//  Created by Beverly, Noah on 3/9/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#include "Timer.hpp"
#include <iostream>

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer :: resetTimer()
{
    executionTime = 0;
}

void Timer :: startTimer()
{
    executionTime = clock();
}

void Timer :: finishTimer()
{
    executionTime = clock() - executionTime;
}

void Timer :: displayTimerInformation()
{
    cout << "It took this long to execute: " << executionTime << endl;
    cout << "That is this man seconds: " << executionTime/CLOCKS_PER_SEC << endl;
}

long Timer :: getExecutionTimeInMicroseconds()
{
    return executionTime;
}
