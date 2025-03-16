#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF (int)(pow(10, 11))

int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int A = nextInt(); // Read the number of temples
    int B = nextInt(); // Read the number of shrines
    int Q = nextInt(); // Read the number of queries

    int *s = (int *)malloc((A + 2) * sizeof(int)); // Create a dynamic array for temples
<<<<<<< HEAD
    s[0] = -INF; 
    s[A + 1] = INF; 
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt(); // Read temple locations
    }

    int *t = (int *)malloc((B + 2) * sizeof(int)); // Create a dynamic array for shrines
    t[0] = -INF; 
    t[B + 1] = INF; 
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt(); // Read shrine locations
    }
=======
    s[0] = -INF; // Set boundary value
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt(); // Read temple locations
    }
    s[A + 1] = INF; // Set boundary value

    int *t = (int *)malloc((B + 2) * sizeof(int)); // Create a dynamic array for shrines
    t[0] = -INF; // Set boundary value
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt(); // Read shrine locations
    }
    t[B + 1] = INF; // Set boundary value
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < Q; i++) {
        int x = nextInt(); // Read the query point

<<<<<<< HEAD
        // Find closest temples and shrines
        int b = 0, d = 0;
        while (b <= A && s[b] < x) b++;
        while (d <= B && t[d] < x) d++;

        int res = INF; // Initialize result with infinity
        for (int j = b - 1; j <= b; j++) { // Check previous and current temple
            for (int k = d - 1; k <= d; k++) { // Check previous and current shrine
                if (j >= 0 && j <= A && k >= 0 && k <= B) {
                    int S = s[j];
                    int T = t[k];
                    int d1 = abs(S - x) + abs(T - S);
                    int d2 = abs(T - x) + abs(S - T);
                    res = min(res, min(d1, d2)); // Update result with minimum distance
                }
=======
        // Binary search for the closest temple
        int b = 0;
        for (int j = 1; j <= A + 1; j++) {
            if (s[j] < x) {
                b = j;
            } else {
                break;
            }
        }

        // Binary search for the closest shrine
        int d = 0;
        for (int j = 1; j <= B + 1; j++) {
            if (t[j] < x) {
                d = j;
            } else {
                break;
            }
        }

        int res = INF; // Initialize result with infinity
        for (int S = s[b]; S <= s[b + 1]; S++) { // Check previous and current temple
            for (int T = t[d]; T <= t[d + 1]; T++) { // Check previous and current shrine
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min(res, min(d1, d2)); // Update result with minimum distance
>>>>>>> 98c87cb78a (data updated)
            }
        }

        printf("%d\n", res); // Print the minimum distance for the query
    }

    free(s); // Free allocated memory for temples
    free(t); // Free allocated memory for shrines
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
