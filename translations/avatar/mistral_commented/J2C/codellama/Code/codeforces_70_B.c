
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Initialize n
    char input[100000]; // Initialize input
    int max = -1; // Initialize max to -1
    int msgLength[100000]; // Initialize msgLength array with size n/2
    int count = 0; // Initialize count to 0
    int idx = 0; // Initialize index to 0

    scanf("%d", &n); // Read the number of messages
    scanf("%s", input); // Read the string of messages

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i]; // Read the character at index i

        if (c == '.' || c == '?' || c == '!') { // If character is a question mark, exclamation mark or period
            msgLength[idx++] = ++count; // Increment count and store it in msgLength array
            if (count > max) max = count; // Update max if count is greater than current max
            i++; // Increment i as we have read one more character
            count = 0; // Reset count as we have started a new message
        } else count++; // Increment count if character is not a question mark, exclamation mark or period
    }

    // Check if the total length of messages is greater than n
    if (max > n) {
        printf("Impossible\n"); // Print "Impossible" if total length is greater than n
        return 0;
    }

    int ans = 0; // Initialize answer to 0

    // Loop through each message and find the maximum number of messages that can be sent
    for (int i = 0; i < idx; i++) {
        int l = msgLength[i]; // Initialize length of current message

        while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) { // While we can add next message to current message
            l += msgLength[i + 1] + 1; // Add length of next message and 1 for separator
            i++; // Increment i to move to next message
        }
        ans++; // Increment answer as we have added one more message
    }

    printf("%d\n", ans); // Print the answer

    return 0;
}

