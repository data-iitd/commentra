#include <stdio.h> // Including standard input-output library

#define MOD 1000000007 // Defining a constant value for modulus

int main() { // Main function to start the program
    int n, q; // Variables to store the length of the string and number of queries
    scanf("%d %d", &n, &q); // Reading the first two integer inputs

    char c[n + 1]; // Declaring a character array to store the string
    scanf("%s", c); // Reading the string

    int range[q][2]; // Declaring a 2D array to store the range of each query

    for (int i = 0; i < q; i++) { // Loop to read the range of each query
        scanf("%d %d", &range[i][0], &range[i][1]); // Reading the starting and ending index of the range
    }

    int frag[n + 1]; // Declaring an array to store the frequency of 'AC' substring
    int rui[n + 1]; // Declaring an array to store the running sum of 'AC' substring frequency

    // Initializing frag and rui arrays to 0
    for (int i = 0; i <= n; i++) {
        frag[i] = 0;
        rui[i] = 0;
    }

    for (int i = 2; i <= n; i++) { // Loop to iterate through the string from index 2 to the end
        if (c[i - 2] == 'A' && c[i - 1] == 'C') { // Checking if the current position is an 'AC' substring
            frag[i]++; // Incrementing the frequency of 'AC' substring at the current position
        }
        rui[i] = rui[i - 1] + frag[i]; // Updating the running sum of 'AC' substring frequency
    }

    for (int i = 0; i < q; i++) { // Loop to iterate through each query
        int left = range[i][0]; // Storing the starting index of the current query range
        int right = range[i][1]; // Storing the ending index of the current query range
        printf("%d\n", rui[right] - rui[left]); // Printing the result of the current query
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
