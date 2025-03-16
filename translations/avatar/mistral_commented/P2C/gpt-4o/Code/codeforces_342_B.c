#include <stdio.h>

int main() {
    int n, m, s, f;
    
    // Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
    scanf("%d %d %d %d", &n, &m, &s, &f);

    // Check if the starting position is less than the final position
    int d;
    char c;
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    // Initialize an empty string to store the output
    char res[100000]; // Assuming the output will not exceed 100000 characters
    int index = 0;

    // Initialize variables i and j with initial values
    int i = 1;
    int j = s;

    // Read the first track: three integers t, l, and r representing the length, left end, and right end of a track
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);

    // Initialize a variable k to keep track of the number of tracks
    int k = 1;

    // While the current position j is not equal to the final position f
    while (j != f) {
        // If we have read all the tracks or the current position i is not in the current track
        if (i > t && k < m) {
            // Read the next track: three integers t, l, and r
            scanf("%d %d %d", &t, &l, &r);
            // Increment the number of tracks
            k++;
        }

        // If the current position i is in the current track
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            // Append 'X' to the output string
            res[index++] = 'X';
        } else {
            // Append the corresponding direction character 'R' or 'L' to the output string
            res[index++] = c;
            // Update the current position j based on the direction
            j += d;
        }
        // Increment the current position i
        i++;
    }

    // Null-terminate the output string
    res[index] = '\0';

    // Print the output string
    printf("%s\n", res);

    return 0;
}

// <END-OF-CODE>
