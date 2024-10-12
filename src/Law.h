#ifndef LAW_H
#define LAW_H

#include <string>
#include "Elt.h"
#include "Signal.h"

// A Signal is the Scalar of the 2 Vector
// THERE ARE DEFAULT SIGNALS


/*
 Elt.Law() => ( gamma )
 (gamma) Elt => Elt.Law() 
 Law : Method - Behaviour
 Gamma : Signal
*/

class Law {
	Elt* elt;
	Signal* emit_func(void*); // A function which can be defined [ Maybe we will define i as a string
	public:
		Law();
		~Law();
		void launch();
		void stop(); // call automaticaly
};

class SignalLaw {
	Signal* received_signal
	Law* Law;
};

class TimerProcess {
	enum nature{ CYCLE, DELAY, SPECIFIC };
	string timer;
	Signal* emit_signal;
};

// We Define more Specific Laws  [ Transforming, Lighting, Shading, Visibiltu Determination, Rendering, Moving, Ray Tracing ... ]

#endif
