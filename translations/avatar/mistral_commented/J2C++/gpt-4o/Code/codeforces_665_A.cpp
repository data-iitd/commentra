#include <iostream> // Include iostream for input and output
#include <sstream> // Include sstream for string stream
#include <string> // Include string for string manipulation
#include <vector> // Include vector for dynamic arrays

using namespace std;

int main() {
    // Create a string to read input
    string line;

    // Read the first line of input and parse the integers
    getline(cin, line); // Read the first line
    istringstream iss1(line); // Create a string stream from the line
    int a, tA;
    iss1 >> a >> tA; // Parse the first integer (number of students) and time taken by student A

    // Read the second line of input and parse the integers
    getline(cin, line); // Read the second line
    istringstream iss2(line); // Create a string stream from the line
    int b, tB;
    iss2 >> b >> tB; // Parse the second integer (number of students in bus B) and time taken by bus B

    // Read the third line of input and parse the string
    getline(cin, line); // Read the string representing the bus timing
    int hrs = stoi(line.substr(0, 2)); // Parse the hours from the string
    int mins = stoi(line.substr(3)); // Parse the minutes from the string
    int simDeparture = hrs * 60 + mins; // Calculate the simulation time of bus departure
    int simArrival = simDeparture + tA; // Calculate the simulation time of bus arrival

    int counter = 0; // Initialize the counter to 0

    // Loop through the bus timings to find the number of buses that can accommodate students
    for (int i = 300; i < 1440; i += b) { // Loop through the bus timings from 300 to 1439 in increments of busB
        int busDeparture = i; // Store the bus departure time
        int busArrival = i + tB; // Calculate the bus arrival time

        if (busDeparture >= simArrival || simDeparture >= busArrival) { // Check if the bus departure or arrival time is after the simulation time
            continue; // If so, skip to the next iteration of the loop
        }
        counter++; // Increment the counter if the bus timing is valid
    }

    // Write the output to the console
    cout << counter << endl; // Print the number of buses that can accommodate students

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
