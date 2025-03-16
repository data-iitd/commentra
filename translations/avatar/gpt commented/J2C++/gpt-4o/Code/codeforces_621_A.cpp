#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For sorting
using namespace std;

int main() {
    // Creating a variable to hold the number of elements to be processed
    int n;
    cin >> n;

    // Initializing a vector to store the input numbers
    vector<long long> list(n);

    // Reading n long integers from input and adding them to the list
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    // Initializing a vector to store odd numbers and a variable to hold the sum
    vector<long long> odd;
    long long sum = 0;

    // Iterating through the list to separate even and odd numbers
    for (long long i : list) {
        if (i % 2 == 0) {
            // If the number is even, add it to the sum
            sum += i;
        } else {
            // If the number is odd, add it to the odd vector
            odd.push_back(i);
        }
    }

    // Sorting the vector of odd numbers in ascending order
    sort(odd.begin(), odd.end());

    // Adding all odd numbers to the sum
    for (long long i : odd) {
        sum += i;
    }

    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (odd.size() % 2 != 0) {
        sum -= odd[0];
    }

    // Printing the final calculated sum
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
