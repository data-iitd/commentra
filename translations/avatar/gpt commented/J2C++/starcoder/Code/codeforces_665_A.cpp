#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the first line of input and tokenize it to get values for 'a' and 'tA'
    string line;
    getline(cin, line);
    istringstream ss(line);
    int a, tA;
    ss >> a >> tA;
    
    // Read the second line of input and tokenize it to get values for 'b' and 'tB'
    getline(cin, line);
    ss = istringstream(line);
    int b, tB;
    ss >> b >> tB;
    
    // Read the third line of input which contains the time in "HH:MM" format
    getline(cin, line);
    int hrs = stoi(line.substr(0, 2)); // Extract hours
    int mins = stoi(line.substr(3)); // Extract minutes
    
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
    
    // Flush the output stream and close the PrintWriter
    return 0;
}

