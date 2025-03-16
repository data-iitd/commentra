#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    // Read two integers n and k from input
    scanf("%d %d", &n, &k);

    // Read the string of values (v) from input
    char v[100]; // Assuming the maximum length of v is 100
    scanf("%s", v);

    // Define the directions for movement: LEFT and RIGHT
    const char *d[] = {"LEFT", "RIGHT"};

    // Determine if we should move LEFT or RIGHT based on the position k
    // If k is closer to the start (LEFT), f will be 1; otherwise, it will be 0
    int f = (k - 1) < (n - k);

    // Calculate the minimum number of moves needed to reach the desired position
    int m = (k - 1) < (n - k) ? (k - 1) : (n - k);

    // Initialize an array to store the sequence of moves and prints
    char a[200][20]; // Assuming a maximum of 200 commands, each up to 20 characters
    int index = 0;

    // Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
    for (int i = 0; i < m; i++) {
        strcpy(a[index++], d[!f]); // Append the opposite direction of f
    }

    // Append the print commands for each character in the string v
    // The slicing reverses the order of characters if moving RIGHT (f is 1)
    for (int i = (f ? strlen(v) - 1 : 0), step = (f ? -1 : 1); 
         (f ? i >= 0 : i < strlen(v)); 
         i += step) {
        sprintf(a[index++], "PRINT %c", v[i]); // Append the print command for the current character
        strcpy(a[index++], d[f]);              // Append the direction for the next move
    }

    // Print the final sequence of moves and print commands, excluding the last move
    for (int i = 0; i < index - 1; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}

// <END-OF-CODE>
