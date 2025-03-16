#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, tA, b, tB;
    int hrs, mins;
    int simDeparture, simArrival;
    int counter = 0;

    // Read the first line of input and tokenize it to get values for 'a' and 'tA'
    scanf("%d %d", &a, &tA);

    // Read the second line of input and tokenize it to get values for 'b' and 'tB'
    scanf("%d %d", &b, &tB);

    // Read the third line of input which contains the time in "HH:MM" format
    char timing[6];
    scanf("%s", timing);

    // Parse the hours and minutes from the input time
    hrs = (timing[0] - '0') * 10 + (timing[1] - '0'); // Extract hours
    mins = (timing[3] - '0') * 10 + (timing[4] - '0'); // Extract minutes

    // Convert the input time to total minutes since midnight
    simDeparture = hrs * 60 + mins;

    // Calculate the simulated arrival time by adding 'tA' to the departure time
    simArrival = simDeparture + tA;

    // Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
    for (int i = 300; i < 1440; i += b) {
        int busDeparture = i; // Current bus departure time
        int busArrival = i + tB; // Calculate bus arrival time

        // Check if the bus schedule overlaps with the simulated arrival time
        if (busDeparture >= simArrival || simDeparture >= busArrival)
            continue; // If there's no overlap, skip to the next bus

        // If there is an overlap, increment the counter
        counter++;
    }

    // Output the total count of valid bus schedules
    printf("%d\n", counter);

    return 0;
}
