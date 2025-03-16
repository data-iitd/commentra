#include <iostream> // Including required header for input and output
#include <vector>   // Including required header for vector
#include <unordered_map> // Including required header for unordered_map
using namespace std;

int main() {
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from the input
    vector<int> ara(n); // Creating a vector of size n
    unordered_map<int, int> map; // Creating an empty unordered_map to store the frequency of each integer

    // Reading elements of the array and updating the frequency in the unordered_map
    for (int i = 0; i < n; i++) {
        int v; // Variable to store the current integer
        cin >> v; // Reading an integer from the input
        ara[i] = v; // Storing the integer in the vector
        map[v]++; // Incrementing the frequency of the integer in the unordered_map
    }

    // Finding the maximum frequency in the unordered_map
    int max_freq = 0;
    for (const auto& pair : map) {
        max_freq = max(max_freq, pair.second); // Updating max_freq with the maximum frequency found so far
    }

    // Finding the element(s) with the maximum frequency
    unordered_map<int, int> mm; // Creating an empty unordered_map to store the elements and their frequencies
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == 0) { // Checking if the current element is already present in the unordered_map
            mm[ara[i]] = 1; // If not, add it with a frequency of 1
            if (mm[ara[i]] == max_freq) { // Checking if the frequency of the current element is equal to the maximum frequency
                cout << ara[i] << endl; // If yes, print it and break out of the loop
                break;
            }
        } else {
            mm[ara[i]]++; // If the current element is already present, increment its frequency by 1
            if (mm[ara[i]] == max_freq) { // Checking if the frequency of the current element is equal to the maximum frequency
                cout << ara[i] << endl; // If yes, print it and break out of the loop
                break;
            }
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
