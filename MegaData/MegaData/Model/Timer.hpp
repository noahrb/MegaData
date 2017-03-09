//
//  Timer.hpp
//  MegaData
//
//  Created by Beverly, Noah on 3/9/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>

class Timer
{
private: clock_t executionTime;
    
public:
    Timer();
    void startTimer();
    void finishTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExeecutionTimeInMicroseconds();
};
#endif /* Timer_hpp */
