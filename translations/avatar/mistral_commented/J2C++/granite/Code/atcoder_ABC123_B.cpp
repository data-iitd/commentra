
#include <iostream> // Including the necessary header file for input/output operations
#include <map> // Including the necessary header file for using the map container

using namespace std; // Using the'std' namespace for the standard library

int main() { // Main function to start the program
    int a[5], r[5]; // Declaring integer arrays 'a' and 'r' of size 5
    map<int, int> map; // Declaring an empty map to store integer keys and their corresponding integer values

    // Reading input elements of array 'a' and storing their remainders in array 'r'
    for (int i = 0; i < 5; i++) {
        cin >> a[i]; // Reading an integer value from the console and storing it in the 'i'th index of array 'a'
        r[i] = a[i] % 10; // Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

        int b = 10; // Initializing 'b' to 10
        if (r[i]!= 0) { // Checking if the remainder of the 'i'th element of array 'a' is not zero
            b = 10 - r[i]; // Calculating the complement of the remainder and assigning it to 'b'
            map[b] = a[i]; // Storing the complement as a key and the corresponding integer value (the 'i'th element of array 'a') in the map
        }
    }

    int ans = 0; // Initializing 'ans' to zero

    // Checking if the map is empty
    if (map.empty()) {
        for (int i = 0; i < 5; i++) { // Iterating through the array 'a'
            ans += a[i]; // Adding the 'i'th element of array 'a' to the sum 'ans'
        }
        cout << ans << endl; // Printing the sum of all elements in array 'a'
        return 0; // Exiting the function if the map is empty
    }

    int last = map[map.rbegin()->first]; // Getting the last key (complement) from the map and finding its corresponding value (the last element of array 'a')
    int idx = 0; // Initializing 'idx' to zero

    // Finding the index of the last element in array 'a'
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) { // Checking if the 'i'th element of array 'a' is equal to the last element
            idx = i; // If true, assigning the index to 'idx'
            break; // Exiting the loop
        }
    }

    // Calculating the sum of all elements in array 'a' except the last one
    for (int i = 0; i < 5; i++) {
        if (i!= idx) { // Checking if the current index is not equal to 'idx'
            if (a[i] % 10 == 0) { // Checking if the 'i'th element of array 'a' is a multiple of 10
                ans += a[i]; // If true, adding it to the sum 'ans'
            } else { // If the 'i'th element of array 'a' is not a multiple of 10
                ans += a[i] + (10 - r[i]); // Adding the 'i'th element of array 'a' and its complement to the sum 'ans'
            }
        }
    }

    // Adding the last element of array 'a' to the sum 'ans'
    ans += last;

    cout << ans << endl; // Printing the final sum

    return 0; // Ending the program
}

