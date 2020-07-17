//==============================================================================
//  This is the header file for a phasor oscillator class.    ==================
//==============================================================================

#include <iostream>
#include <cmath>

#pragma once // guard so that the header is included only once

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
        double gen(double amp, double freq);
};

// construction
Phasor::Phasor(double SR) {
    srate = SR;
    output = 0.0;
    std::cout << "Construction of Phasor object." << std::endl;
}

// destruction
Phasor::~Phasor(void) {
    std::cout << "Destruction of Phasor object." << std::endl;
}

// sample generation
double Phasor::gen(double amp, double freq) {
    // recalculate incr at each sample for CPU-consumption consistency
    incr = freq / srate;
    // integrate frequency slope and wrap-around
    output = output - std::floor(output) + incr;
    return amp * output;
}

