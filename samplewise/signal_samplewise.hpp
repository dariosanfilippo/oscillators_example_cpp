//==============================================================================
//  This is the header file for a SIGNAL base-class to generate individual 
//  samples on demand by calling a function. The class contains the samplerate 
//  information, set by the user when instantiating an object, which is 
//  accessible by the derived classes.
//==============================================================================

#include <iostream>
#include <cmath>

# define TWOPI 2 * M_PI // 2π

// guard so that the header is included only once
#pragma once

class Signal {
    // dataspace
    protected:
        int srate;
    // methodspace
    public:
        // constructor and destructor declaration
        Signal(int SR);
        ~Signal(void);
};

// constructor
Signal::Signal(int SR) {
    srate = SR;
    std::cout << "Construction of Signal object." << std::endl;
}

// destructor
Signal::~Signal(void) {
    std::cout << "Destruction of Signal object." << std::endl;
}
