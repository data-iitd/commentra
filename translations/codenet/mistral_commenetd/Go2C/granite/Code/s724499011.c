

#include <stdio.h>

int main() {
    // Initialize variables
    int n;
    scanf("%d", &n); // Read the number of elements in the string's'
    char s[n];
    scanf("%s", s); // Read the string's'
    int ns[n]; // Create an array 'ns' of length 'n' to store the color index for each character in's'

    // Read the string's' into 'ns'
    for (int i = 0; i < n; i++) {
        // Assign color index to 'ns' based on the character in's'
        switch (s[i]) {
            case 'R':
                ns[i] = 0;
                break;
            case 'G':
                ns[i] = 1;
                break;
            case 'B':
                ns[i] = 2;
                break;
        }
    }

    // Initialize 'rgb' array with zeros
    int rgb[n+1][3];
    rgb[0][0] = rgb[0][1] = rgb[0][2] = 0; // First row of 'rgb' array to store the total RGB values for each color
    for (int i = 1; i <= n; i++) {
        // Initialize each inner row of 'rgb' array with zeros
        rgb[i][0] = rgb[i][1] = rgb[i][2] = 0;
        for (int j = 0; j < 3; j++) {
            rgb[i][j] = rgb[i-1][j]; // Initialize each cell with the value of the corresponding cell in the previous row
        }
        // Increment the value of the cell in the current row and column based on the color index of the previous character
        rgb[i][ns[i-1]]++;
    }

    // Calculate the sum of differences between adjacent rows in 'rgb' array
    int sum = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            // Check if the characters in the current and next indices have different colors
            if (ns[i]!= ns[j]) {
                // Calculate the total difference between the corresponding cells in the 'rgb' array
                int tn = 3 - ns[i] - ns[j];
                sum += rgb[n][tn]; // Get the total RGB value of the last cell in the last row with the complementary color
                sum -= rgb[j+1][tn]; // Subtract the total RGB value of the first cell in the next row with the complementary color

                // Check if there is a character with the same color index between the current and next indices
                int k = 2*j - i;
                if (k < n && ns[k] == tn) {
                    sum--; // Decrease the sum if there is a character with the same color index between the current and next indices
                }
            }
        }
    }

    // Print the final result
    printf("%d\n", sum);
    // End of the code
    return 0;
}

