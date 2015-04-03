//*** Creates a timer object that can be used to accurately time stuff ***//

#include "timer.h"

double CTimer::readTimer() {
    // use the <sys/time.h> to get time in s and us convert to ms
    double elapsedTime;

    elapsedTime = (stopTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (stopTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    return elapsedTime;
}

double CTimer::readTimerSec() {
    // use the <sys/time.h> to get time in s and us convert to ms, then return in s
    double elapsedTime;

    elapsedTime = (stopTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (stopTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    return elapsedTime/1000.0;
}

double CTimer::readLapTime() {
    // Create a new stoptime without affecting any private variable
    timeval lapTime;
    gettimeofday(&lapTime, NULL);

    double elapsedTime;

    elapsedTime = (lapTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (lapTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    return elapsedTime;
}

double CTimer::readLapTimeSec() {
    // Create a new stoptime without affecting any private variable
    timeval lapTime;
    gettimeofday(&lapTime, NULL);

    double elapsedTime;

    elapsedTime = (lapTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (lapTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    return elapsedTime/1000.0;
}