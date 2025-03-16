#include <iostream> // Including necessary header for input and output
#include <vector>   // Including vector header for using vectors
#include <algorithm> // Including algorithm header for using max function

using namespace std; // Using the standard namespace

// Function to read long integers from input
long long readLong() {
    long long x;
    cin >> x; // Reading a long integer from standard input
    return x; // Returning the read integer
}

int main() {
    vector<long long> a(4); // Declaring and initializing a vector of long long integers with size 4

    for (int i = 0; i < 4; i++) { // Iterating through the elements of the vector a
        a[i] = readLong(); // Reading the next long integer from the input and storing it in the current element of the vector
    }

    // Calculating the maximum product of pairs of elements in the vector a
    long long result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])));

    cout << result << endl; // Printing the result to the standard output

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
