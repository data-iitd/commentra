#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d\n", &n); // Read the integer n
    char input[1000]; // Assuming the input length won't exceed 1000 characters
    fgets(input, sizeof(input), stdin); // Read the input string

    int max = -1;
    int msgLength[500]; // Assuming the maximum number of messages won't exceed 500
    int count = 0;
    int idx = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count;
            if (count > max) max = count;
            i++; // Skip the punctuation
            count = 0;
        } else {
            count++;
        }
    }

    if (max > n) {
        printf("Impossible\n");
    } else {
        int ans = 0;
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i];
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1;
                i++;
            }
            ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
