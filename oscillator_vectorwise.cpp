//==============================================================================
//  This is the main program for an example code that shows the use of classes
//  and inheritance to print samples of a sinewave on screen.
//
//  This algorithm shows a vector-wise design for audio signal functions
//  that is 'on demand': the functions return a pointer to a new 
//  vector of data whenever they are called.
//
//  Copyright (C) 2020 Dario Sanfilippo – sanfilippo.dario@gmail.com
//==============================================================================

#include <iostream>
#include <cmath>
#include "phasor_vectorwise.hpp"
#include "sine_vectorwise.hpp"

int main(void) {
    double* sine_s;
    double* phasor_s;
    int SR = 96000;
    int VS = 64;
    int n_vectors = 2;
    double amp = 1.0;
    double freq = 2000.0;
    Phasor phasor(SR, VS);
    Sine sine(SR, VS);
    std::cout.precision(16);
    for (int i = 0; i < n_vectors; i++) {
        phasor_s = phasor.gen(amp, freq);
        sine_s = sine.gen(amp, freq);
        for (int j = 0; j < VS; j++) {
            std::cout << phasor_s[j] << "\t" << sine_s[j] << std::endl;
        }
    }
    return 0;
}
