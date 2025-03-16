#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Define the maximum size of the array to avoid array out of bounds exception
    int N = 1e5 + 5;

    // Initialize an array to store the count of each number
    long cnt[21] = {0};

    // Read the numbers one by one and update the count array accordingly
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        cnt[num + 10]++;
    }

    // Calculate the result using the given formula
    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Print the result to the console
    printf("%ld\n", res);

    return 0;
}

