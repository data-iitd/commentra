#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation and conversions

int main() {
    int a, tA; // Declare variables for number of students and time taken by student A
    int b, tB; // Declare variables for number of students in bus B and time taken by bus B
    char timing[6]; // Declare a string to hold the bus timing in "HH:MM" format

    // Read the first line of input and parse the integers
    scanf("%d %d", &a, &tA); // Read number of students and time taken by student A

    // Read the second line of input and parse the integers
    scanf("%d %d", &b, &tB); // Read number of students in bus B and time taken by bus B

    // Read the third line of input (bus timing)
    scanf("%s", timing); // Read the string representing the bus timing
    int hrs = (timing[0] - '0') * 10 + (timing[1] - '0'); // Parse the hours from the string
    int mins = (timing[3] - '0') * 10 + (timing[4] - '0'); // Parse the minutes from the string
    int simDeparture = hrs * 60 + mins; // Calculate the simulation time of bus departure
    int simArrival = simDeparture + tA; // Calculate the simulation time of bus arrival

    int counter = 0; // Initialize the counter to 0

    // Loop through the bus timings to find the number of buses that can accommodate students
    for (int i = 300; i < 1440; i += b) { // Loop through the bus timings from 300 to 1439 in increments of busB
        int busDeparture = i; // Store the bus departure time
        int busArrival = i + tB; // Calculate the bus arrival time

        // Check if the bus departure or arrival time is after the simulation time
        if (busDeparture >= simArrival || simDeparture >= busArrival) {
            continue; // If so, skip to the next iteration of the loop
        }
        counter++; // Increment the counter if the bus timing is valid
    }

    // Write the output to the console
    printf("%d\n", counter); // Print the number of buses that can accommodate students

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
