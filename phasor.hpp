//==============================================================================
//  This is the header file for a phasor oscillator class.    ==================
//==============================================================================

#include <iostream>
#include <cmath>

#pragma once // guard so that the header is included only once

using namespace std;

class Phasor {
    // dataspace, private by default
    private:
        double srate; // samplerate
        double incr; // phase increment
        double output; // output sample
    // methodspace
    public:
        // constructor declaration
        Phasor(double SR);
        // default destructor
        ~Phasor(void);
        // generation function declaration
        double gen(double freq);
};

// construction
Phasor::Phasor(double SR) {
    srate = SR;
    output = 0.0;
    cout << "Construction of Phasor object." << endl;
}

// destruction
Phasor::~Phasor(void) {
    cout << "Destruction of Phasor object." << endl;
}

// sample generation
double Phasor::gen(double freq) {
    // recalculate incr at each sample for CPU-consumption consistency
    incr = freq / srate;
    // integrate frequency slope and wrap-around
    output = output - floor(output) + incr;
    return output;
}

