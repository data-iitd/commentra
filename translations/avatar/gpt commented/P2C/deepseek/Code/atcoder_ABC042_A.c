#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
    scanf("%d %d %d", &a, &b, &c);

    // Check if the number 5 appears exactly twice in the tuple
    if (a == 5 && b == 5) {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        printf("%s\n", (a + b + c == 17) ? "YES" : "NO");
    } else if (a == 5 && c == 5) {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        printf("%s\n", (a + b + c == 17) ? "YES" : "NO");
    } else if (b == 5 && c == 5) {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        printf("%s\n", (a + b + c == 17) ? "YES" : "NO");
    } else {
        // If 5 does not appear exactly twice, print 'NO'
        printf("NO\n");
    }

    return 0;
}
