//==============================================================================
//  This is the header file for a PHASOR oscillator class. The class is 
//  derived from the SIGNAL base-class and the samplerate and vector size
//  are provided when instantiating an object. The class contains public a 
//  method, "gen", that can be used to generate vectors of samples of a phasor 
//  oscillator whenever the function is called. The function is called with 
//  frequency and amplitude parameters that can be modulated in real-time.
//==============================================================================

#include "signal_vectorwise.hpp"

// guard so that the header is included only once
#pragma once

class Phasor : public Signal {
    // dataspace, private by default
    private:
        double incr; // frequency slope
        double integrator;
        double* vector;
    // methodspace
    public:
        // constructor and destructor declaration
        Phasor(int SR, int VS);
        ~Phasor(void);
        // vector-generating function declaration
        double* gen(double A, double F);
};

// construction
Phasor::Phasor(int SR, int VS) : Signal(SR, VS) {
    integrator = 0.0;
    vector = new double [VS];
    for (int i = 0; i < VS; i++) {
        vector[i] = 0.0;
    }
    std::cout << "Construction of Phasor object." << std::endl;
}

// destruction
Phasor::~Phasor(void) {
    delete[] vector;
    std::cout << "Destruction of Phasor object." << std::endl;
}

// vector generation
double* Phasor::gen(double A, double F) {
    for (int i = 0; i < vsize; i++) {
        // recalculate incr at each sample for CPU-consumption consistency
        incr = F / (double)srate;
        // integrate frequency slope and wrap-around
        integrator = integrator - std::floor(integrator) + incr;
        vector[i] = A * integrator;
    }
    return vector;
}

