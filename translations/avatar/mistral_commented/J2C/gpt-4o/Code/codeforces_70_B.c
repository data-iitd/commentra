#include <stdio.h>  // Include standard input-output library
#include <stdlib.h> // Include standard library for memory allocation and conversions

int main() {
    int n; // Variable to store the number of messages
    scanf("%d\n", &n); // Read the number of messages

    char input[10000]; // Array to store the input string (assuming a maximum length)
    fgets(input, sizeof(input), stdin); // Read the string of messages

    int max = -1; // Initialize max to -1
    int msgLength[5000]; // Initialize msgLength array (assuming a maximum of 5000 messages)
    int count = 0; // Initialize count to 0
    int idx = 0; // Initialize index to 0

    // Loop through each character in the input string
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i]; // Read the character at index i

        // If character is a question mark, exclamation mark or period
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count; // Increment count and store it in msgLength array
            if (count > max) max = count; // Update max if count is greater than current max
            count = 0; // Reset count as we have started a new message
        } else {
            count++; // Increment count if character is not a question mark, exclamation mark or period
        }
    }

    // Check if the total length of messages is greater than n
    if (max > n) {
        printf("Impossible\n"); // Print "Impossible" if total length is greater than n
        return 0; // Exit the program
    }

    int ans = 0; // Initialize answer to 0

    // Loop through each message and find the maximum number of messages that can be sent
    for (int i = 0; i < idx; i++) {
        int l = msgLength[i]; // Initialize length of current message

        // While we can add next message to current message
        while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
            l += msgLength[i + 1] + 1; // Add length of next message and 1 for separator
            i++; // Increment i to move to next message
        }
        ans++; // Increment answer as we have added one more message
    }

    printf("%d\n", ans); // Print the answer
    return 0; // Exit the program
}

// <END-OF-CODE>
