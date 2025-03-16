#include <stdio.h>

int get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    int i;
    for (i = 0; i < num; i++) {
        if (i < t % num) {
            printf("%d ", t / num + 1);
        } else {
            printf("%d ", t / num);
        }
    }
    printf("\n");
}

int main() {
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    get_nums(k, sk);
    get_nums(n - k, sa - sk);

    return 0;
}

