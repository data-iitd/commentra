#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors
#include <set>      // Include the set library for storing unique elements
#include <algorithm> // Include the algorithm library for sorting
using namespace std; // Use the standard namespace

int main() {
    try { // Begin try block to handle exceptions
        int n; // Variable to store the number of elements
        cin >> n; // Read the number of elements from user input

        // Create a set to store unique elements
        set<int> uniqueElements;
        for (int i = 0; i < n; i++) { // Iterate through the input elements
            int value; // Variable to store the input value
            cin >> value; // Read the next input value
            uniqueElements.insert(value); // Add the value to the set (automatically handles uniqueness)
        }

        // Create a vector from the set and sort it
        vector<int> a(uniqueElements.begin(), uniqueElements.end());

        // Check if there exists a sequence of three consecutive elements with a difference of 1
        bool found = false;
        for (size_t i = 0; i < a.size(); i++) { // Iterate through the vector elements
            if (i + 1 < a.size() && i + 2 < a.size()) { // Check if the next and next-next elements exist
                if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) { // Check if the difference is 1
                    found = true; // Set the found flag if a sequence is found
                    break; // Exit the loop if a sequence is found
                }
            }
        }

        // Write the output to the console
        cout << (found ? "YES" : "NO") << endl;

    } catch (...) { // Catch any exceptions
        cerr << "An error occurred." << endl; // Print error message
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
