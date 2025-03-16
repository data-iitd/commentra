#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[32]; // Assuming a 32-bit integer, we need a buffer to store the binary representation.
    int index = 0;

    while (n > 0) {
        s[index++] = (n % 2) + '0'; // Convert the remainder to a character and store it in the buffer.
        n /= 2;
    }

    int ans = 0;
    for (int i = 0; i < index; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
