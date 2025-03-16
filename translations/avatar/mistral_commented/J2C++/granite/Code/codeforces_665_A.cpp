

#include <iostream> // Include the necessary libraries
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
 int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter = 0;
 string timing;
 cin >> a >> tA >> b >> tB >> timing; // Read the input values
 hrs = stoi(timing.substr(0, 2)); // Convert the hours from the string to an integer
 mins = stoi(timing.substr(3)); // Convert the minutes from the string to an integer
 simDeparture = hrs * 60 + mins; // Calculate the simulation time of bus departure
 simArrival = simDeparture + tA; // Calculate the simulation time of bus arrival

 for (int i = 300; i < 1440; i += b) { // Loop through the bus timings from 300 to 1439 in increments of busB
 int busDeparture = i; // Store the bus departure time
 int busArrival = i + tB; // Calculate the bus arrival time

 if (busDeparture >= simArrival || simDeparture >= busArrival) { // Check if the bus departure or arrival time is after the simulation time
 continue; // If so, skip to the next iteration of the loop
 }
 counter++; // Increment the counter if the bus timing is valid
 }

 cout << counter << endl; // Print the number of buses that can accommodate students
 return 0;
}

