//==============================================================================
//  This is the header file for a Sine class to generate samples for a 
//  sinusoidal oscillation. The class is derived from the Phasor class that is
//  in turn derived from the Signal class. The Sine class has a public 
//  method, "gen", that can be called to generate individual samples from 
//  the oscillator. The function is called with amplitude and frequency 
//  parameters that can be modulated in real-time.
//==============================================================================

#include "phasor_samplewise.hpp"

#pragma once // guard so that the header is included only once

class Sine : public Phasor {
    // dataspace
    private:
        double sample;
    // methodspace
    public:
        // constructor and destructor declaration
        Sine(int SR);
        ~Sine(void);
        // sample-generating function declaration
        double gen(double A, double F);
};

// construction
Sine::Sine(int SR) : Phasor(SR) {
    sample = 0.0;
    std::cout << "Construction of Sine object." << std::endl;
}

// destruction
Sine::~Sine(void) {
    std::cout << "Destruction of Sine object." << std::endl;
}

// sample generation
double Sine::gen(double A, double F) {
    sample = std::sin(Phasor::gen(TWOPI, F));
    return A * sample;
}

