
#include <stdio.h>

int main() {
    // Input the value of h
    int h;
    scanf("%d", &h);

    // Loop to calculate the answer
    int ans = 0, cnt = 1;
    while (h!= 1) {
        if (h % 2!= 0) {
            h--; // Decrement h if it is odd
        }
        h /= 2; // Divide h by 2
        cnt *= 2; // Double the count
        ans += cnt; // Increment the sum by the current count
    }

    // Output the final result
    printf("%d\n", ans + 1);
}


