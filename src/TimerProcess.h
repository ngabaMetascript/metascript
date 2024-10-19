#ifndef TIMERPROCESS_H
#define TIMERPROCESS_H

#include <string>
#include "Signal.h"

// Based on time alteration we launch sme signals
class TimerProcess {
	enum nature{ CYCLE, DELAY, SPECIFIC };
	string timer;
	Signal* emit_signal;
};

#endif
