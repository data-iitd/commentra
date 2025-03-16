

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Create variables to store input values
    int a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter;

    // Read the first train's details
    string input;
    getline(cin, input);
    stringstream ss(input);
    ss >> a >> tA;

    // Read the second train's details
    getline(cin, input);
    ss.clear();
    ss.str(input);
    ss >> b >> tB;

    // Read the current timing
    getline(cin, input);
    ss.clear();
    ss.str(input);
    ss >> hrs >> mins;
    simDeparture = hrs * 60 + mins;
    simArrival = simDeparture + tA;

    // Initialize counter to keep track of conflicts
    counter = 0;

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
