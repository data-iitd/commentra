#include <iostream> // Including the iostream library for input and output
#include <algorithm> // Including the algorithm library for the min function
#include <cmath> // Including the cmath library for the ceil function

using namespace std; // Using the standard namespace

int main() {
    // Reading the first long integer input N
    long long N;
    cin >> N;

    // Initializing the minimum long integer variable with the first input value
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        long long current;
        cin >> current; // Read the current input value
        if (i == 0) { // If it's the first iteration of the loop
            min = current; // Set the minimum value to the current input value
        } else { // Otherwise
            min = std::min(min, current); // Update the minimum value with the current input value if it's smaller
        }
    }

    // Printing the answer
    cout << static_cast<long long>(ceil(static_cast<double>(N) / min)) + 4 << endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
