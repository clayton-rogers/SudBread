#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>

/**
 * Creates a timer that can be started stopped. Precision good to at least 0.01
 * milliseconds.
 */
class CTimer {
    timeval startTime;
    timeval stopTime;
    bool is_started;
    bool is_elapsed_time_set;
    double elapsed_time; // in ms
public:
    CTimer ();
    /**
     * Starts the timer.
     */
    void startTimer ();

    /**
     * Stops the timer. It must be started before it can be stopped.
     */
    void stopTimer ();

    /**
     * Reads the value on the timer. The timer must be stopped before it can be read.
     *
     * Returns: The time (in ms) on the timer when it was stopped.
     */
    double readTimer() const;
};

#endif
