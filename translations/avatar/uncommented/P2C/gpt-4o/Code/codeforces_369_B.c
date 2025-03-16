#include <stdio.h>

void get_nums(int num, int t, int *result) {
    for (int i = 0; i < num; i++) {
        if (i < t % num) {
            result[i] = t / num + 1;
        } else {
            result[i] = t / num;
        }
    }
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);
    
    int ans[100]; // Assuming the maximum size of the result array is 100
    int index = 0;

    get_nums(sk, k, ans);
    index += sk;

    get_nums(n - k, sa - sk, ans + index);
    
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
