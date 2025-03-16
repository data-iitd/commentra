
#include <stdio.h>

int main() {
    int n, k;
    char v[100001];
    char d[2][10] = {"LEFT", "RIGHT"};
    int f, m, i;
    char a[200001][10];
    int j = 0;

    // Read two integers n and k from input, where n is the total number of elements and k is the position of interest
    scanf("%d %d", &n, &k);

    // Read the string of values (v) from input
    scanf("%s", v);

    // Determine if we should move LEFT or RIGHT based on the position k
    // If k is closer to the start (LEFT), f will be 0; otherwise, it will be 1
    f = k - 1 < n - k;

    // Calculate the minimum number of moves needed to reach the desired position
    m = k - 1 < n - k? k - 1 : n - k;

    // Append the necessary number of LEFT or RIGHT moves to the array a
    for (i = 0; i < m; i++) {
        strcpy(a[j], d[f]);  // Copy the direction of movement to a[j]
        j++;
    }

    // Append the print commands for each character in the string v
    // The slicing reverses the order of characters if moving RIGHT (f is 1)
    for (i = 0; i < n; i++) {
        strcpy(a[j], "PRINT ");  // Copy the "PRINT " command to a[j]
        j++;
        strcat(a[j], &v[i]);  // Copy the current character to a[j]
        j++;
        strcpy(a[j], d[1 - f]);  // Copy the direction of movement to a[j]
        j++;
    }

    // Print the final sequence of moves and print commands, excluding the last move
    for (i = 0; i < j - 1; i++) {
        printf("%s\n", a[i]);  // Print the command at index i
    }

    return 0;
}
