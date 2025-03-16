

#include <stdio.h>
#include <string.h>

int main() {
    // Create variables to store input values
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, i, busDeparture, busArrival, counter;
    
    // Read the first train's details
    scanf("%d %d", &a, &tA);
    
    // Read the second train's details
    scanf("%d %d", &b, &tB);
    
    // Read the current timing
    char timing[5];
    scanf("%s", timing);
    hrs = (timing[0] - '0') * 10 + (timing[1] - '0');
    mins = (timing[3] - '0') * 10 + (timing[4] - '0');
    
    // Calculate the simulated departure and arrival times for train a
    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;
    
    // Initialize counter to keep track of conflicts
    counter = 0;
    
    // Iterate through the bus schedule, checking for conflicts
    for (i = 300; i < 1440; i += b) {
        busDeparture = i; // Bus departure time
        busArrival = i + tB; // Bus arrival time
        
        // Check if there's a conflict (bus and train schedules overlap)
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue;
        
        // Increment counter if a conflict is found
        counter++;
    }
    
    // Print the number of conflicts found
    printf("%d\n", counter);
    
    return 0;
}
