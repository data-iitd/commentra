

#include <iostream> // Include the iostream library for input/output operations
#include <vector> // Include the vector library for dynamic arrays
#include <algorithm> // Include the algorithm library for sorting and other operations

using namespace std;

int main() {
  try { // Begin try block to handle exceptions
    int n; // Declare and initialize the number of elements in the list
    cin >> n; // Read the number of elements from the user input

    vector<int> a(n); // Create a vector to store the unique and sorted list elements
    for (int i = 0; i < n; i++) { // Iterate through the input elements
      cin >> a[i]; // Read the next input value
    }

    // Sort the vector using the sort function from the algorithm library
    sort(a.begin(), a.end()); // Sort the vector in ascending order

    // Remove duplicate elements from the vector using the unique function from the algorithm library
    a.erase(unique(a.begin(), a.end()), a.end()); // Remove duplicate elements

    // Check if there exists a sequence of three consecutive elements with a difference of 1
    bool found = false;
    for (int i = 0; i < a.size(); i++) { // Iterate through the vector elements
      if (i + 1 < a.size() && i + 2 < a.size()) { // Check if the next and next-next elements exist
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) { // Check if the difference is 1
          found = true; // Set the found flag if a sequence is found
          break; // Exit the loop if a sequence is found
        }
      }
    }

    // Write the output to the console
    cout << (found? "YES" : "NO") << endl; // Output the result as "YES" or "NO"

  } catch (exception& e) { // Catch any exceptions and print the error message
    cerr << "Error: " << e.what() << endl;
  }

  return 0; // Return 0 to indicate successful execution
}

