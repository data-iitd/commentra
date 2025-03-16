#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    // Taking input values for x, y, a, and b

    int games[10000][2]; // Assuming a maximum of 10000 pairs
    int count = 0; // To keep track of the number of valid pairs

    for (int i = a; i <= x; i++) {
        // Looping from a to x
        if (i <= b) continue; // Skipping values of i that are less than or equal to b

        for (int j = b; j <= y; j++) {
            // Looping from b to y
            if (i > j) {
                // Checking if i is greater than j
                games[count][0] = i; // Storing i in the games array
                games[count][1] = j; // Storing j in the games array
                count++; // Incrementing the count of valid pairs
            }
        }
    }

    printf("%d\n", count); // Printing the length of the games list
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", games[i][0], games[i][1]); // Printing each tuple in the games list
    }

    return 0;
}
// <END-OF-CODE>
