#include <stdio.h>

int main() {
    // Variables to store train details
    int a, tA, b, tB;
    
    // Read the first train's details
    scanf("%d %d", &a, &tA);
    
    // Read the second train's details
    scanf("%d %d", &b, &tB);
    
    // Read the current timing
    char timing[6]; // HH:MM format
    scanf("%s", timing);
    
    // Extract hour and minute from timing
    int hrs = (timing[0] - '0') * 10 + (timing[1] - '0'); // Convert to integer
    int mins = (timing[3] - '0') * 10 + (timing[4] - '0'); // Convert to integer
    
    // Calculate the simulated departure and arrival times for train a
    int simDeparture = hrs * 60 + mins; 
    int simArrival = simDeparture + tA; 
    
    // Initialize counter to keep track of conflicts
    int counter = 0; 
    
    // Iterate through the bus schedule, checking for conflicts
    for (int i = 300; i < 1440; i += b) { 
        int busDeparture = i; // Bus departure time
        int busArrival = i + tB; // Bus arrival time
        
        // Check if there's a conflict (bus and train schedules overlap)
        if (busDeparture >= simArrival || simDeparture >= busArrival) continue; 
        
        // Increment counter if a conflict is found
        counter++; 
    } 
    
    // Print the number of conflicts found
    printf("%d\n", counter); 
    
    return 0; 
}

// <END-OF-CODE>
