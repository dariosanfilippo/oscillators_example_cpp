//==============================================================================
//  This is the header file for a sinewave oscillator class.   =================
//==============================================================================

#include <iostream>
#include <cmath>
#include "phasor.hpp"

#pragma once // guard so that the header is included only once

# define TWOPI 2 * M_PI // 2π

using namespace std;

class Sine : public Phasor {
    // dataspace, private by default
    private:
        double output;
    // methodspace
    public:
        // constructor declaration
        Sine(double SR);
        // default destructor
        ~Sine(void);
        // generation function declaration
        double gen(double amp, double freq);
};

// construction
Sine::Sine(double SR) : Phasor(SR) {
    cout << "Construction of Sine object." << endl;
}

// destruction
Sine::~Sine(void) {
    cout << "Destruction of Sine object." << endl;
}

// sample generation
double Sine::gen(double amp, double freq) {
    output = amp * sin(TWOPI * Phasor::gen(freq));
    return output;
}

