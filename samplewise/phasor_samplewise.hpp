//==============================================================================
//  This is the header file for a PHASOR oscillator class. The class is 
//  derived from the SIGNAL base-class and the samplerate is provided when
//  instantiating an object. The class contains public a method, "gen", that
//  can be used to generate individual samples of a phasor oscillator 
//  whenever the function is called. The function is called with frequency and 
//  amplitude parameters that can be modulated in real-time.
//==============================================================================

#include "signal_samplewise.hpp"

// guard so that the header is included only once
#pragma once

class Phasor : public Signal {
    // dataspace
    private:
        double incr; // frequency slope
        double integrator;
    // methodspace
    public:
        // constructor and destructor declaration
        Phasor(int SR);
        ~Phasor(void);
        // sample-generating function declaration
        double gen(double A, double F);
};

// construction
Phasor::Phasor(int SR) : Signal(SR) {
    srate = SR;
    integrator = 0.0;
    std::cout << "Construction of Phasor object." << std::endl;
}

// destruction
Phasor::~Phasor(void) {
    std::cout << "Destruction of Phasor object." << std::endl;
}

// sample generation
double Phasor::gen(double A, double F) {
    // recalculate incr at each sample for CPU-consumption consistency
    incr = F / (double)srate;
    // integrate frequency slope and wrap-around
    integrator = integrator + incr;
    integrator = integrator - std::floor(integrator);
    return A * integrator;
}

