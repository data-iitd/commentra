#include <iostream> // Include iostream for input and output
#include <unordered_set> // Include unordered_set for storing unique differences
#include <vector> // Include vector for dynamic array
#include <string> // Include string for handling strings

using namespace std;

int main() {
    int n, m; // Declare variables for number of strings and possibly unused variable
    cin >> n >> m; // Read the first two integer inputs

    vector<string> arrs(n); // Declare and initialize vector to store strings
    for (int i = 0; i < n; i++) {
        cin >> arrs[i]; // Read each string and store it in the vector
    }

    vector<int> length(n); // Declare and initialize vector to store differences
    int index = 0; // Initialize index for the length vector
    int returnDex = 0; // Initialize returnDex to store the result

    for (const string& tmp : arrs) { // Loop through each string in the vector
        int dexG = tmp.find('G'); // Find the index of 'G' in the string
        int dexS = tmp.find('S'); // Find the index of 'S' in the string
        if (dexG > dexS) { // Check if 'G' comes after 'S'
            returnDex = -1; // Set returnDex to -1 if 'G' is after 'S'
        }
        length[index++] = dexS - dexG; // Calculate and store the difference in length vector
    }

    unordered_set<int> set; // Initialize unordered_set to store unique differences
    for (int len : length) { // Loop through each difference in the length vector
        set.insert(len); // Add the difference to the unordered_set
    }

    if (returnDex == -1) { // Check if returnDex is -1
        cout << returnDex << endl; // Print -1 if 'G' comes after 'S'
    } else {
        cout << set.size() << endl; // Print the size of the unordered_set if 'G' does not come after 'S'
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
