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
#include "sine.hpp"

using namespace std;

int main(void) {
    // creation of Sine object, inherited from Phasor object
    Sine ph1(96000.0);
    // number of samples to generate
    long int samples = 96;
    double amp = 1.0;
    double freq = 2000.0;
    for (int i = 0; i < 96; i++) {
        cout << ph1.gen(amp, freq) << endl;
    }
    return 0;
}
