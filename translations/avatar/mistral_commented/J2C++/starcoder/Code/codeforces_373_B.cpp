
#include <bits/stdc++.h>
using namespace std;

// Initialize answer variable to 0
long long ans = 0;

// Function to calculate the sum of digits from position 'a' to the end
long long get(long long a) {
    long long ret = 0; // Initialize result to 0
    long long now = 1; // Initialize current position to 1
    long long t = 1; // Initialize multiplier to 1
    for (; ; ) {
        // Calculate the sum of digits from current position to the end
        if (now * 10 > a) {
            ret += (a - now + 1) * t; // Add the sum of digits from current position to the end
            break;
        }
        ret += now * 9 * t; // Add the sum of digits from current position to the next position
        now *= 10; // Move to the next position
        t++; // Increment the multiplier
    }
    return ret; // Return the sum of digits
}

// Binary search function to find the position of the number that satisfies the condition
long long binarySearch(long long k, long long l, long long r, long long x) {
    // Base case: if the search range is empty, return -1
    if (r >= l) {
        long long mid = l + (r - l) / 2; // Calculate the middle index
        // Check if the middle index is the answer and if it satisfies the condition
        if (mid > ans && mid * k <= x) {
            ans = mid; // Update the answer if it satisfies the condition
        }

        // Check if the middle index is the answer
        if (k * mid == x) {
            return mid; // Return the answer if it is the answer
        }

        // Recursively search in the left subtree if the condition is not satisfied
        if (k * mid > x) {
            return binarySearch(k, l, mid - 1, x);
        }

        // Recursively search in the right subtree if the condition is not satisfied
        return binarySearch(k, mid + 1, r, x);
    }

    // Base case: if the search range is empty, return -1
    return -1;
}

// Initialize input and output streams
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

// Main function to read input and calculate the answer
int main() {
    long long gen, st, tim; // Initialize variables for input
    cin >> gen >> st >> tim; // Read the number of generations
    gen /= tim; // Calculate the number of generations per second
    long long beg = st - 1, end = (long long) pow(10, 18); // Initialize the search range
    // Binary search to find the position of the number that satisfies the condition
    while (true) {
        long long med = (beg + end) / 2 + 1; // Calculate the middle index
        if (get(med) - get(st - 1) > gen) { // Check if the middle index generates more digits than the given limit
            end = med - 1; // Narrow the search range to the left if it generates more digits
        } else {
            beg = med; // Narrow the search range to the right if it generates less digits
        }
        if (beg == end) { // Check if the search range is empty
            cout << beg - st + 1 << "\n"; // Print the answer if the search range is empty
            break;
        }
    }
    return 0;
}
