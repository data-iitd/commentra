#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

int main() { // Starting point of the program
    int n, levels; // Declaring variables for n and levels
    cin >> n >> levels; // Reading the first two integer inputs

    int sum = 0; // Initializing sum variable to 0
    int sum2 = 0; // Initializing sum2 variable to 0
    int sum3 = 0; // Initializing sum3 variable to 0
    vector<int> arr(levels); // Creating a vector 'arr' of size 'levels'

    for (int i = 0; i < levels; i++) { // Loop to read 'levels' number of integers and store them in 'arr'
        cin >> arr[i];
    }

    int level2; // Declaring variable for level2
    cin >> level2; // Reading the third integer input 'level2'
    int level3 = levels + level2; // Calculating the size of 'arr2'
    vector<int> arr2(level3); // Creating a vector 'arr2' of size 'level3'

    for (int i = 0; i < arr.size(); i++) { // Loop to copy elements of 'arr' to 'arr2'
        arr2[i] = arr[i];
    }

    for (int i = arr.size(); i < level3; i++) { // Loop to read 'level2' number of integers and store them in 'arr2'
        cin >> arr2[i];
    }

    vector<int> arr3(n); // Creating a vector 'arr3' of size 'n'
    for (int i = 0; i < n; i++) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
        arr3[i] = i + 1;
    }

    int count = 0; // Initializing count variable to 0

    for (int i = 0; i < n; i++) { // Outer loop to compare each element of 'arr3' with 'arr2'
        for (int x = 0; x < arr2.size(); x++) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
            if (arr3[i] == arr2[x]) { // If a match is found
                count++; // Increment the count variable
                break; // Exit the inner loop
            }
        }
    }

    if (count == n) { // If all elements of 'arr3' are present in 'arr2'
        cout << "I become the guy." << endl; // Print the message
    } else { // Otherwise
        cout << "Oh, my keyboard!" << endl; // Print the error message
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
