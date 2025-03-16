
#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip> 

using namespace std; 

int main() { 
    // Initialize variables to store input values
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter; 
    string timing; 
    
    // Read the first line of input and extract values for 'a' and 'tA'
    cin >> a >> tA; 
    
    // Read the second line of input and extract values for 'b' and 'tB'
    cin >> b >> tB; 
    
    // Read the third line of input which contains the time in "HH:MM" format
    cin >> timing; 
    
    // Parse the hours and minutes from the input time
    stringstream ss(timing); 
    ss >> hrs >> mins; 
    simDeparture = hrs * 60 + mins; // Calculate the simulated departure time
    
    // Calculate the simulated arrival time by adding 'tA' to the departure time
    simArrival = simDeparture + tA; 
    
    // Initialize the counter to keep track of valid bus schedules
    counter = 0; 
    
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
    
    // Return 0 to indicate successful execution
    return 0; 
}
