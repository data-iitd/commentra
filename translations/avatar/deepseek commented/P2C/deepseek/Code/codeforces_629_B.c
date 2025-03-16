#include <stdio.h>
#include <stdlib.h>

#define MAX_TIME_SLOTS 368

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Consume the newline character after reading N

    // Initialize arrays to store changes for males and females
    int m[MAX_TIME_SLOTS] = {0};
    int f[MAX_TIME_SLOTS] = {0};

    // Read each operation
    for (int i = 0; i < N; i++) {
        char x;
        int a, b;
        scanf("%c %d %d", &x, &a, &b);
        getchar(); // Consume the newline character after reading the line
        b++; // Adjust end time to be inclusive

        // Update the changes in the arrays based on gender
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    int a = 0, b = 0, c = 0;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for (int i = 0; i < MAX_TIME_SLOTS; i++) {
        a += m[i];
        b += f[i];
        if (a < b ? a : b > c) {
            c = a < b ? a : b;
        }
    }

    // Print the maximum number of people at any time slot
    printf("%d\n", c);

    return 0;
}
