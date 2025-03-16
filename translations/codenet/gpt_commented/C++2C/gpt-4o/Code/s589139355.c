#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables to hold scores and lengths
    int a, t = 0, h = 0, lt, lh, tt, hh, l;

    // Read the number of rounds
    scanf("%d", &a);

    // Declare arrays to hold names of players
    char taro[100], hana[100];

    // Loop through each round
    for (int i = 0; i < a; ++i) {
        // Read the names of the players for the current round
        scanf("%s %s", taro, hana);

        // Get the lengths of the names
        lt = strlen(taro);
        lh = strlen(hana);

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
        if (strcmp(taro, hana) > 0) {
            t += 3; // Taro wins this round
        } else if (strcmp(hana, taro) > 0) {
            h += 3; // Hana wins this round
        } else {
            h += 1; // Tie: both get 1 point
            t += 1; // Tie: both get 1 point
        }
    }

    // Output the final scores of Taro and Hana
    printf("%d %d\n", t, h);

    return 0; // End of the program
}

// <END-OF-CODE>
