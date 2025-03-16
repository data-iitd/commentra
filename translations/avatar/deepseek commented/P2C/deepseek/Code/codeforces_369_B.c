#include <stdio.h>

int* get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    int* result = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        result[i] = t / num + (i < t % num ? 1 : 0);
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;

    // Read input values for n, k, l, r, sa, and sk
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    int* ans1 = get_nums(k, sk);
    int* ans2 = get_nums(n - k, sa - sk);

    // Print the result as a space-separated string of numbers
    for (int i = 0; i < k; i++) {
        printf("%d ", ans1[i]);
    }
    for (int i = 0; i < n - k; i++) {
        printf("%d ", ans2[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ans1);
    free(ans2);

    return 0;
}
