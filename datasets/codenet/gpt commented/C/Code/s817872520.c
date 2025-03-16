// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

#define INF 0x5fffffff // Define a constant for infinity
int a[100002]; // Array to hold the values of the evacuation route
int b[100002]; // Array to hold the computed values for the evacuation route

char buf[700002], *p; // Buffer for input and pointer to traverse it

// Function to read an integer from the input buffer
int getint()
{
    int n = 0; // Initialize the integer to store the result
    // Check for negative sign
    if (*p == '-') {
        p++; // Move to the next character
        while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf); // Convert characters to integer
        return -n; // Return the negative integer
    }
    // Convert characters to integer for positive numbers
    while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
    return n; // Return the positive integer
}

int main()
{
    int w, i, k, f, close, ans; // Declare variables for width, indices, flags, close distance, and answer

    // Read the width of the evacuation route
    fgets(p=buf, 10, stdin), w = getint();
    // Read the evacuation route values
    fgets(p=buf, sizeof(buf), stdin);
    
    // Initialize answer and flags, and process the route values
    for (ans = 0, f = 0, i = 1; i <= w; i++) {
        a[i] = k = getint(), p++; // Read the next integer into array a
        if (!k) f |= 1; // Set flag if value is zero
        else if (k < 0) f |= 2; // Set flag if value is negative
        else ans += k; // Accumulate positive values into ans
    }
    
    // Check for special cases: no positive values or only zeros
    if (!ans || !(f & 1)) { puts("0"); return 0; }
    // If there are no negative values, print the total sum
    if (!(f & 2)) { printf("%d\n", ans); return 0; }

    // Calculate the minimum distance to the closest zero from the left
    for (close = 0, f = 0, i = 1; i <= w; i++) {
        if (!a[i]) close = INF, f = -1; // Reset close distance if zero is found
        else if (a[i] < 0) {
            // Update close distance if a negative value is found
            if (f < 0 || close - (i-f) > -a[i]) close = -a[i], f = i;
        } else {
            // Calculate the distance to the closest zero for positive values
            if (f < 0) b[i] = INF; // If no zero found, set to infinity
            else {
                k = close - (i-f); if (k < 0) k = 0; // Calculate distance
                b[i] = k; // Store the distance in array b
            }
        }
    }

    // Calculate the minimum distance to the closest zero from the right
    for (close = 0, f = w, i = w; i >= 1; i--) {
        if (!a[i]) close = INF, f = -1; // Reset close distance if zero is found
        else if (a[i] < 0) {
            // Update close distance if a negative value is found
            if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
        } else {
            // Calculate the distance to the closest zero for positive values
            if (f < 0) b[i] = INF; // If no zero found, set to infinity
            else {
                k = close - (f-i); if (k < 0) k = 0; // Calculate distance
                if (k > b[i]) b[i] = k; // Update if the new distance is smaller
            }
        }
    }

    // Calculate the final answer based on the minimum distances
    for (ans = 0, i = 1; i <= w; i++) {
        if (a[i] > 0) {
            // Add the minimum of the positive value or the calculated distance
            if (b[i] > a[i]) ans += a[i];
            else             ans += b[i];
        }
    }
    
    // Print the final answer
    printf("%d\n", ans);
    return 0; // Exit the program
}
