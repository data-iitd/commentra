#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Initialize variables for input
    int a, tA, b, tB;
    
    // Read the first line of input for 'a' and 'tA'
    cin >> a >> tA;
    
    // Read the second line of input for 'b' and 'tB'
    cin >> b >> tB;
    
    // Read the third line of input which contains the time in "HH:MM" format
    string timing;
    cin >> timing;
    
    // Parse the hours and minutes from the input time
    int hrs = stoi(timing.substr(0, 2)); // Extract hours
    int mins = stoi(timing.substr(3)); // Extract minutes
    
    // Convert the input time to total minutes since midnight
    int simDeparture = hrs * 60 + mins; 
    
    // Calculate the simulated arrival time by adding 'tA' to the departure time
    int simArrival = simDeparture + tA; 
    
    // Initialize a counter to keep track of valid bus schedules
    int counter = 0; 
    
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
    cout << counter << endl; 
    
    return 0;
}

// <END-OF-CODE>
