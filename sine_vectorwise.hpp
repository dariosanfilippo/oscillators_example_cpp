//==============================================================================
//  This is the header file for a Sine class to generate vectors of samples 
//  for sinusoidal oscillation. The class is derived from the Phasor class 
//  that is in turn derived from the Signal class. The Sine class has a public 
//  method, "gen", that can be called to generate vectors of samples from 
//  the oscillator. The function is called with amplitude and frequency 
//  parameters that can be modulated in real-time.
//==============================================================================

#include "phasor_vectorwise.hpp"

// guard so that the header is included only once
#pragma once 

class Sine : public Phasor {
    // dataspace
    private:
        double* samples;
        double* vector;
    // methodspace
    public:
        // constructor and destructor declaration
        Sine(int SR, int VS);
        ~Sine(void);
        // vector-generating function declaration
        double* gen(double A, double F);
};

// construction
Sine::Sine(int SR, int VS) : Phasor(SR, VS) {
    vector = new double [VS];
    for (int i = 0; i < VS; i++) {
        vector[i] = 0.0;
    }
    std::cout << "Construction of Sine object." << std::endl;
}

// destruction
Sine::~Sine(void) {
    delete[] vector;
    std::cout << "Destruction of Sine object." << std::endl;
}

// vector generation
double* Sine::gen(double A, double F) {
    samples = Phasor::gen(TWOPI, F);
    for (int i = 0; i < vsize; i++) {
        vector[i] = A * std::sin(samples[i]);
    }
    return vector;
}

