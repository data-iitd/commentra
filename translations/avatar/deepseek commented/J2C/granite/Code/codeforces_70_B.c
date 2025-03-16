
#include <stdio.h> // Include the necessary header files
#include <string.h>

int main() {
    int n; // Declare the necessary variables
    char input[1000]; // Input text
    int max = -1; // Maximum message length
    int msgLength[500]; // Array to store message lengths
    int count = 0; // Counter for message length
    int idx = 0; // Index for the msgLength array

    // Read the maximum length for each message and the input text
    scanf("%d", &n);
    fgets(input, sizeof(input), stdin);

    // Iterate through the input string to determine message lengths
    for (int i = 0; input[i]!= '\0'; i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            msgLength[idx++] = ++count; // Store the length of the current message and increment the index
            if (count > max) max = count; // Update the maximum message length if necessary
            i++; // Skip the next character as it is part of the next message
            count = 0; // Reset the counter for the next message
        } else {
            count++; // Increment the counter for the current message length
        }
    }

    // Check if the maximum message length exceeds the allowed maximum
    if (max > n) {
        printf("Impossible\n"); // Print "Impossible" if the maximum message length is too large
    } else {
        int ans = 0; // Initialize the answer variable to store the number of messages
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i]; // Get the length of the current message
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1; // Group messages that fit within the maximum length
                i++; // Move to the next message
            }
            ans++; // Increment the answer as we have a complete message
        }
        printf("%d\n", ans); // Print the total number of messages required
    }

    return 0; // Return 0 to indicate successful execution
}
