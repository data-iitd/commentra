#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
    // Declare variables to hold scores and lengths
    int a, t = 0, h = 0, lt, lh, tt, hh, l;

    // Read the number of rounds
    cin >> a;

    // Declare strings to hold names of players
    string taro, hana;

    // Loop through each round
    for (int i = 0; i < a; ++i) {
        // Read the names of the players for the current round
        cin >> taro >> hana;

        // Get the lengths of the names
        lt = taro.length();
        lh = hana.length();

        // Determine the longer name length
        if (lt > lh) {
            l = lt; // Taro's name is longer
        } else {
            l = lh; // Hana's name is longer or they are equal
        }

        // Initialize scores for this round
        tt = 0;
        hh = 0;

        // Compare the names and update scores based on the comparison
        if (taro > hana) {
            t = t + 3; // Taro wins this round
        } else if (hana > taro) {
            h = h + 3; // Hana wins this round
        } else if (hana == taro) {
            h = h + 1; // Tie: both get 1 point
            t = t + 1; // Tie: both get 1 point
        }
    }

    // Output the final scores of Taro and Hana
    cout << t << " " << h << endl;

    return 0; // End of the program
}
