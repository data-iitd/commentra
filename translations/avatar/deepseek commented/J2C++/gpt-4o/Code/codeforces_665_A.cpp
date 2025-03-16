#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Create variables to store train details
    int a, tA, b, tB;
    
    // Read the first train's details
    cin >> a >> tA;
    
    // Read the second train's details
    cin >> b >> tB;
    
    // Read the current timing
    string timing;
    cin >> timing;
    int hrs = stoi(timing.substr(0, 2)); // Extract hour from timing
    int mins = stoi(timing.substr(3));    // Extract minute from timing
    
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
    cout << counter << endl; 
    
    return 0;
}

// <END-OF-CODE>
