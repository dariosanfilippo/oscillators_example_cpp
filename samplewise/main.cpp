//==============================================================================
//  This is the main program for an example code that shows the use of classes
//  and inheritance to print samples of a sinewave on screen.
//
//  This algorithm shows a sample-wise design for audio signal functions
//  that is 'on demand': the functions return a new sample whenever 
//  they are called.
//
//  Copyright (C) 2020 Dario Sanfilippo – sanfilippo.dario@gmail.com
//==============================================================================

#include "phasor_samplewise.hpp"
#include "sine_samplewise.hpp"

int main(void) {
    int SR = 96000;
    int n_samples = 192;
    double amp = 1.0;
    double freq = 2000.0;
    Phasor phasor(SR);
    Sine sinusoid(SR);
    std::cout.precision(16);
    for (int i = 0; i < n_samples; i++) {
        std::cout << phasor.gen(amp, freq) << "\t" << 
            sinusoid.gen(amp, freq) << "\t" << std::endl;
    }
    return 0;
}
