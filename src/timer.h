/*	timer.h		v0.3
 * 
 * class CTimer
 * 		Creates a timer that can be started stopped
 * 		and has a laptimer. Precision good to at least
 * 		0.01 milliseconds
 * 
 * 
 * DEPENDENCIES:
 * 	<sys/time.h>
 * 		
 * 
 * TODO:
 * 	make a way of restarting from the previous time value
 * 	^ this can be done fairly easily from within the program
 * 
 * 
 * 
 * FUNCTIONS:
 * 
 * startTime
 * 	reset and starts the clock
 * 	note that when the timer is created it starts running
 * 
 * stopTime
 * 	stops the clock
 * 	note the time can only be read once the timer has been stopped
 * 
 * readTimer
 * 	get the time that was on the clock when it was stopped
 * 	outputs in milliseconds
 * 
 * readTimerSec
 * 	get the time that was on the clock when it was stopped
 * 	outputs in seconds
 * 
 * readLapTime
 * 	returns the time that is currently on the timer without
 * 	stopping it
 * 	outputs in milliseconds
 * 
 * readLapTimeSec
 * 	returns the time that is currently on the timer without
 * 	stopping it
 * 	outputs in seconds
 * 
 * Clayton Rogers
 * Mar 2010
 */


#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>			// for gettimeofday()

class CTimer {
    timeval startTime;
    timeval stopTime;
public:
    CTimer () {
        // Set both start and stop time to now
        // The start time is last so that getting the stoptime is not included in the run
        gettimeofday(&stopTime, NULL);
        gettimeofday(&startTime, NULL);
    }
    void startTimer () {
        // Reset start and stop time to now
        // The start time is last so that getting the stoptime is not included in the run
        gettimeofday(&stopTime, NULL);
        gettimeofday(&startTime, NULL);
    }
    void stopTimer () {
        // Set the stop time to now
        gettimeofday(&stopTime, NULL);
    }
    double readTimer();
    double readTimerSec();
    double readLapTime();
    double readLapTimeSec();
};

#endif
