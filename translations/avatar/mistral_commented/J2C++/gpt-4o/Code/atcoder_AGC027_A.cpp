#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library to use the vector container
#include <algorithm> // Including the algorithm library for sorting

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int N; // Variable to store the number of elements
    long x; // Variable to store the target value

    cin >> N; // Reading the number of elements from standard input
    cin >> x; // Reading the target value from standard input

    vector<long> sweet; // Creating a vector of long type named sweet to store the elements

    for (int i = 0; i < N; i++) { // A for loop to read and add N elements to the vector
        long a; // Variable to store the current element
        cin >> a; // Reading an element from standard input
        sweet.push_back(a); // Adding the element to the vector
    }

    sort(sweet.begin(), sweet.end()); // Sorting the vector in ascending order using the sort() function

    int num = 0; // Initializing a variable named num to keep track of the number of elements that can be subtracted from x

    for (int i = 0; i < N; i++) { // A for loop to find the number of elements that can be subtracted from x
        if (x - sweet[num] >= 0) { // Checking if x is greater than or equal to the current element in the vector
            x -= sweet[num]; // Subtracting the current element from x
            num++; // Incrementing the num variable
        } else { // If x is less than the current element in the vector
            break; // Exiting the for loop
        }
    }

    if ((num == N) && (x > 0)) { // Checking if all the elements in the vector have been subtracted from x and x is still greater than 0
        num -= 1; // Decrementing the num variable by 1 as the last element that was subtracted from x is not included in the count
    }

    cout << num << endl; // Printing the number of elements that can be subtracted from x

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
