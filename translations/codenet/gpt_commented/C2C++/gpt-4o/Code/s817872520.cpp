// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

#include <iostream>
#include <vector>
#include <limits>

#define INF 0x5fffffff // Define a constant for infinity

// Function to read an integer from the input
int getint(std::istream &in) {
    int n = 0; // Initialize the integer to store the result
    char c;
    in >> c; // Read the first character
    bool negative = (c == '-'); // Check for negative sign
    if (negative) {
        in >> c; // Read the next character
    }
    // Convert characters to integer
    do {
        n = n * 10 + (c - '0');
        in >> c; // Read the next character
    } while (c >= '0' && c <= '9');
    return negative ? -n : n; // Return the integer
}

int main() {
    int w; // Width of the evacuation route
    std::cin >> w; // Read the width of the evacuation route
    std::vector<int> a(w + 1); // Array to hold the values of the evacuation route
    std::vector<int> b(w + 1); // Array to hold the computed values for the evacuation route

    // Initialize answer and flags, and process the route values
    int ans = 0, f = 0;
    for (int i = 1; i <= w; i++) {
        a[i] = getint(std::cin); // Read the next integer into array a
        if (a[i] == 0) f |= 1; // Set flag if value is zero
        else if (a[i] < 0) f |= 2; // Set flag if value is negative
        else ans += a[i]; // Accumulate positive values into ans
    }

    // Check for special cases: no positive values or only zeros
    if (ans == 0 || !(f & 1)) {
        std::cout << "0\n";
        return 0;
    }
    // If there are no negative values, print the total sum
    if (!(f & 2)) {
        std::cout << ans << "\n";
        return 0;
    }

    // Calculate the minimum distance to the closest zero from the left
    int close = 0;
    f = 0;
    for (int i = 1; i <= w; i++) {
        if (a[i] == 0) {
            close = INF;
            f = -1; // Reset close distance if zero is found
        } else if (a[i] < 0) {
            // Update close distance if a negative value is found
            if (f < 0 || close - (i - f) > -a[i]) {
                close = -a[i];
                f = i;
            }
        } else {
            // Calculate the distance to the closest zero for positive values
            if (f < 0) b[i] = INF; // If no zero found, set to infinity
            else {
                int k = close - (i - f);
                if (k < 0) k = 0; // Calculate distance
                b[i] = k; // Store the distance in array b
            }
        }
    }

    // Calculate the minimum distance to the closest zero from the right
    close = 0;
    f = w;
    for (int i = w; i >= 1; i--) {
        if (a[i] == 0) {
            close = INF;
            f = -1; // Reset close distance if zero is found
        } else if (a[i] < 0) {
            // Update close distance if a negative value is found
            if (f < 0 || close - (f - i) > -a[i]) {
                close = -a[i];
                f = i;
            }
        } else {
            // Calculate the distance to the closest zero for positive values
            if (f < 0) b[i] = INF; // If no zero found, set to infinity
            else {
                int k = close - (f - i);
                if (k < 0) k = 0; // Calculate distance
                if (k > b[i]) b[i] = k; // Update if the new distance is smaller
            }
        }
    }

    // Calculate the final answer based on the minimum distances
    ans = 0;
    for (int i = 1; i <= w; i++) {
        if (a[i] > 0) {
            // Add the minimum of the positive value or the calculated distance
            if (b[i] > a[i]) ans += a[i];
            else ans += b[i];
        }
    }

    // Print the final answer
    std::cout << ans << "\n";
    return 0; // Exit the program
}

// <END-OF-CODE>
