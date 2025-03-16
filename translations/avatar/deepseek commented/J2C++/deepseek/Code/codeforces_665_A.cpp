#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Read the first train's details
    int a, tA;
    std::cin >> a >> tA;

    // Read the second train's details
    int b, tB;
    std::cin >> b >> tB;

    // Read the current timing
    std::string timing;
    std::getline(std::cin >> std::ws, timing);

    // Extract hour and minute from timing
    int hrs = std::stoi(timing.substr(0, 2));
    int mins = std::stoi(timing.substr(3));

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
    std::cout << counter << std::endl;

    return 0;
}
