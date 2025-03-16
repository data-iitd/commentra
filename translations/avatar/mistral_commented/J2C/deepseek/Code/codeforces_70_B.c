#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char input[100000];
    int max = -1;
    int msgLength[50000];
    int count = 0;
    int idx = 0;

    // Read the number of messages
    scanf("%d", &n);

    // Read the string of messages
    scanf(" %[^\n]", input);

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count;
            if (count > max) max = count;
            i++;
            count = 0;
        } else count++;
    }

    // Check if the total length of messages is greater than n
    if (max > n) {
        printf("Impossible\n");
        return 0;
    }

    int ans = 0;

    // Loop through each message and find the maximum number of messages that can be sent
    for (int i = 0; i < idx; i++) {
        int l = msgLength[i];

        while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
            l += msgLength[i + 1] + 1;
            i++;
        }
        ans++;
    }

    // Print the answer
    printf("%d\n", ans);

