#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Function to compare two integers in descending order
int compare_int(const void *a, const void *b) {
    return *(long int*)b - *(long int*)a; // 大きい順
}

// Function to find the greatest common divisor (GCD) of two integers
long int gcd(long int a, long int b) {
    if (b == 0) {
        // If 'b' is 0, then 'a' is the GCD
        return a;
    } else {
        // Otherwise, recursively call the function with 'b' and the remainder of 'a' divided by 'b'
        return gcd(b, a % b);
    }
}

// Function to find the least common multiple (LCM) of two integers
long int lcm(long int a, long int b) {
    // The LCM is the product of the two numbers divided by their GCD
    return a * b / gcd(a, b);
}

// Main function
int main() {
    long int n; // Number of people
    long long int k; // Total points
    long int q; // Number of queries
    std::vector<long int> a(100001); // Array to store the query numbers
    std::vector<long long int> point(100001, 0); // Array to store the current points for each person

    // Read input values
    std::cin >> n >> k >> q;

    // Check if it's possible to distribute the points to all queries
    if (q < k) {
        // If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
        for (long int i = 0; i < n; i++) {
            std::cout << "Yes\n"; // This will never be reached
            return 0;
        }
    }

    // Distribute the points to each query one by one
    for (long int i = 0; i < q; i++) {
        std::cin >> a[i]; // Read the query number
        point[a[i] - 1]++; // Increase the points for the person with the query number
    }

    // Check if it's possible to distribute the remaining points to the remaining people
    for (long int i = 0; i < n; i++) {
        if (k - (q - point[i]) > 0) { // If the remaining points are greater than the difference between the total points and the points already distributed
            std::cout << "Yes\n"; // It's possible to distribute the remaining points to the remaining people
        } else {
            std::cout << "No\n"; // It's impossible to distribute the remaining points to the remaining people
        }
    }

    return 0;
}

// <END-OF-CODE>
