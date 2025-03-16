#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library to use the vector container
#include <algorithm> // Including the algorithm library for sorting
using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int n; // Variable to store the number of elements
    cin >> n; // Reading the number of elements from standard input

    vector<long> list; // Creating a vector of long type to store n elements
    list.reserve(n); // Reserving space for n elements

    for (int i = 0; i < n; i++) { // Iterating through the input to add each element to the vector
        long num;
        cin >> num; // Reading each long number
        list.push_back(num); // Adding the number to the vector
    }

    vector<long> odd; // Creating a vector to store odd numbers
    long sum = 0; // Initializing the sum variable to 0

    for (long i : list) { // Iterating through each element in the vector
        if (i % 2 == 0) // Checking if the current element is even
            sum += i; // Adding the even number to the sum
        else
            odd.push_back(i); // Adding the odd number to the odd vector
    }

    sort(odd.begin(), odd.end()); // Sorting the odd vector in ascending order

    for (long i : odd) // Iterating through each odd number in the sorted odd vector
        sum += i; // Adding the odd number to the sum

    if (odd.size() % 2 != 0) // Checking if the size of the odd vector is odd
        sum -= odd[0]; // Subtracting the first odd number if the size is odd

    cout << sum << endl; // Printing the final sum to the standard output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
