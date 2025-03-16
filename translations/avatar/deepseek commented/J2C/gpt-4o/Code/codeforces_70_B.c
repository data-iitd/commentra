#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and conversions

int main() {
    int n; // Variable to store the maximum length for each message
    scanf("%d\n", &n); // Reading the maximum length for each message

    char input[10000]; // Assuming a maximum input length
    fgets(input, sizeof(input), stdin); // Reading the input text

    int max = -1; // Initializing the maximum message length to -1
    int msgLength[5000]; // Initializing an array to store the lengths of each message
    int count = 0; // Initializing a counter for the current message length
    int idx = 0; // Index for the msgLength array

    // Iterating through the input string to determine message lengths
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i]; // Getting the current character
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count; // Storing the length of the current message and incrementing the index
            if (count > max) max = count; // Updating the maximum message length if necessary
            i++; // Skipping the next character as it is part of the next message
            count = 0; // Resetting the counter for the next message
        } else {
            count++; // Incrementing the counter for the current message length
        }
    }

    // Checking if the maximum message length exceeds the allowed maximum
    if (max > n) {
        printf("Impossible\n"); // Printing "Impossible" if the maximum message length is too large
    } else {
        int ans = 0; // Initializing the answer variable to store the number of messages
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i]; // Getting the length of the current message
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1; // Grouping messages that fit within the maximum length
                i++; // Moving to the next message
            }
            ans++; // Incrementing the answer as we have a complete message
        }
        printf("%d\n", ans); // Printing the total number of messages required
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
