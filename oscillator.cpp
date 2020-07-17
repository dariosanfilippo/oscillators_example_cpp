//=============================================================================
//  This is the main program for an example code that shows the use of classes
//  and inheritance to print some samples of a sinewave.
//
//  This algorithm shows a design for a sine-generating function that is
//  "on demand", that is, the function returns a new sample whenever it is
//  called.
//
//  Copyright (C) 2020 Dario Sanfilippo – sanfilippo.dario@gmail.com
//==============================================================================

#include <iostream>
#include <cmath>
#include "phasor.hpp"
#include "sine.hpp"

int main(void) {
    double SR = 96000.0;
    long int samples = 192;
    double amp = 1.0;
    double freq = 2000.0;
    Phasor phasor(SR);
    Sine sinusoid(SR);
    std::cout.precision(16);
    for (int i = 0; i < samples; i++) {
        std::cout << phasor.gen(amp, freq) << "\t" << 
            sinusoid.gen(amp, freq) << std::endl;
    }
    return 0;
}
