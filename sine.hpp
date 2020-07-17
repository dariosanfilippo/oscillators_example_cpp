//==============================================================================
//  This is the header file for a sinewave oscillator class.   =================
//==============================================================================

#include <iostream>
#include <cmath>
#include "phasor.hpp"

#pragma once // guard so that the header is included only once

# define TWOPI 2 * M_PI // 2π

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
    std::cout << "Construction of Sine object." << std::endl;
}

// destruction
Sine::~Sine(void) {
    std::cout << "Destruction of Sine object." << std::endl;
}

// sample generation
double Sine::gen(double amp, double freq) {
    output = std::sin(Phasor::gen(TWOPI, freq));
    return amp * output;
}

