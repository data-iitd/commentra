#include <stdio.h>

#define N 368

int main() {
    // Initialize arrays to store changes for males and females
    int m[N] = {0};
    int f[N] = {0};

    // Read the number of operations
    int operations;
    scanf("%d", &operations);
    getchar(); // To consume the newline character after the number of operations

    for (int i = 0; i < operations; i++) {
        char x;
        int a, b;
        // Read each line, expecting format: Gender StartTime EndTime
        scanf(" %c %d %d", &x, &a, &b);
        b += 1; // Increment end time by 1

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
    int maleCount = 0, femaleCount = 0, maxPeople = 0;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for (int i = 0; i < N; i++) {
        maleCount += m[i];
        femaleCount += f[i];
        if (maleCount < femaleCount && maleCount > maxPeople) {
            maxPeople = maleCount;
        } else if (femaleCount < maleCount && femaleCount > maxPeople) {
            maxPeople = femaleCount;
        }
    }

    // Print the maximum number of people at any time slot
    printf("%d\n", maxPeople);

    return 0;
}

// <END-OF-CODE>
