#include <iostream> // Including the necessary I/O libraries
#include <vector> // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for sorting
#include <string> // Including the string library for string operations

using namespace std; // Using the standard namespace

class c462b { // Class definition for c462b
public:
    int left = 0; // Property to store the count

    bool operator<(const c462b& other) const { // Overloading the less-than operator for comparison
        return left < other.left; // Comparing based on the left property
    }
};

int main() { // Main function definition
    int n, k; // Variables to store the length of the string and the parameter
    cin >> n >> k; // Reading the values of n and k

    vector<c462b> cards(26); // Initializing a vector of c462b objects with 26 elements
    string s; // String to store the input
    cin >> s; // Reading the string from the input

    for (char c : s) { // Looping through the string to count occurrences
        cards[c - 'A'].left++; // Incrementing the left property of the corresponding c462b object
    }

    long long ans = 0; // Initializing the answer variable to zero
    for (int i = 0; i < k; i++) { // Looping k times to calculate the answer
        sort(cards.begin(), cards.end()); // Sorting the cards vector
        long long change = min(cards[25].left, k - i); // Calculating the minimum between the largest left value and the remaining k - i
        ans += change * change; // Adding the square of the calculated value to ans
        cards[25].left -= change; // Decrementing the left property of the largest element
        i += change - 1; // Adjusting the loop counter
    }

    cout << ans << endl; // Printing the result
    return 0; // Returning from the main function
}

// <END-OF-CODE>
