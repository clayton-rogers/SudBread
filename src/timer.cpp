#include <stdexcept>
#include "timer.h"

CTimer::CTimer() :
        is_started(false),
        is_elapsed_time_set(false)
{}

void CTimer::startTimer() {
    // Reset start and stop time to now
    // The start time is last so that getting the stop time is not included in the run
    gettimeofday(&startTime, NULL);
    is_started = true;
    is_elapsed_time_set = false;
}

void CTimer::stopTimer() {
    if (!is_started) {
        throw new std::logic_error("Tried to stop a timer that was not started.");
    }
    // Set the stop time to now
    gettimeofday(&stopTime, NULL);
    is_started = false;

    elapsed_time  = (stopTime.tv_sec  - startTime.tv_sec) * 1000.0;
    elapsed_time += (stopTime.tv_usec - startTime.tv_usec) / 1000.0;
    is_elapsed_time_set = true;
}


double CTimer::readTimer() const{
    if (is_elapsed_time_set) {
        return elapsed_time;
    } else {
        throw new std::logic_error("Tried to read a timer that has not been stopped.");
    }
}

