#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Maximum length for each message
    char input[100000]; // Input text
    int max = -1; // Maximum message length
    int msgLength[100000]; // Array to store message lengths
    int count = 0; // Counter for current message length
    int idx = 0; // Index for msgLength array

    // Reading input
    scanf("%d", &n);
    scanf("%s", input);

    // Iterating through input to determine message lengths
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i]; // Getting current character
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count; // Storing length of current message and incrementing index
            if (count > max) max = count; // Updating maximum message length if necessary
            i++; // Skipping next character as it is part of next message
            count = 0; // Resetting counter for next message
        } else {
            count++; // Incrementing counter for current message length
        }
    }

    // Checking if maximum message length exceeds allowed maximum
    if (max > n) {
        printf("Impossible\n"); // Printing "Impossible" if maximum message length is too large
    } else {
        int ans = 0; // Initializing answer variable to store number of messages
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i]; // Getting length of current message
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1; // Grouping messages that fit within maximum length
                i++; // Moving to next message
            }
            ans++; // Incrementing answer as we have complete message
        }
        printf("%d\n", ans); // Printing total number of messages required
    }

    return 0;
}

