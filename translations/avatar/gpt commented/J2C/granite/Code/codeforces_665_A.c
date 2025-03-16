
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int main() { 
    // Initialize variables to store input values
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter; 
    char timing[10]; // Store the input time in a character array
    
    // Read the first line of input and tokenize it to get values for 'a' and 'tA'
    scanf("%d %d", &a, &tA); 
    
    // Read the second line of input and tokenize it to get values for 'b' and 'tB'
    scanf("%d %d", &b, &tB); 
    
    // Read the third line of input which contains the time in "HH:MM" format
    scanf("%s", timing);  // Read the input time into the character array
    
    // Parse the hours and minutes from the input time
    hrs = (timing[0] - '0') * 10 + (timing[1] - '0'); // Extract hours
    mins = (timing[3] - '0') * 10 + (timing[4] - '0'); // Extract minutes
    
    // Convert the input time to total minutes since midnight
    simDeparture = hrs * 60 + mins;  // Calculate simulated departure time
    
    // Calculate the simulated arrival time by adding 'tA' to the departure time
    simArrival = simDeparture + tA;  // Calculate simulated arrival time
    
    // Initialize the counter to keep track of valid bus schedules
    counter = 0;  // Initialize the counter
    
    // Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
    for (int i = 300; i < 1440; i += b) { 
        int busDeparture = i; // Current bus departure time
        int busArrival = i + tB; // Calculate bus arrival time
        
        // Check if the bus schedule overlaps with the simulated arrival time
        if (busDeparture >= simArrival || simDeparture >= busArrival) 
            continue; // If there's no overlap, skip to the next bus
        
        // If there is an overlap, increment the counter
        counter++; 
    }  // End of the loop
    
    // Output the total count of valid bus schedules
    printf("%d\n", counter);  // Output the counter value
    
    return 0; 
} 
// END-OF-CODE