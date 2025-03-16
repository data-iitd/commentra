#include <stdio.h>

int min(int nums[], int size) {
    int min = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int values[2] = {n * a, b};
    printf("%d\n", min(values, 2));

    return 0;
}

// <END-OF-CODE>
