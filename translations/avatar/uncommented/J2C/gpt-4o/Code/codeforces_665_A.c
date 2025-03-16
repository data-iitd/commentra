#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, tA, b, tB;
    char timing[6]; // HH:MM format
    int hrs, mins, simDeparture, simArrival, counter = 0;

    // Read input for a and tA
    scanf("%d %d", &a, &tA);
    
    // Read input for b and tB
    scanf("%d %d", &b, &tB);
    
    // Read the timing
    scanf("%s", timing);
    
    // Parse hours and minutes
    hrs = (timing[0] - '0') * 10 + (timing[1] - '0');
    mins = (timing[3] - '0') * 10 + (timing[4] - '0');
    
    // Calculate departure and arrival times
    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;

    // Count the number of buses that can be taken
    for (int i = 300; i < 1440; i += b) {
        int busDeparture = i;
        int busArrival = i + tB;
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue;
        counter++;
    }

    // Print the result
    printf("%d\n", counter);

    return 0;
}

// <END-OF-CODE>
