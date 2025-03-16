#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int l1[100]; // Assuming the maximum number of elements in a list is 100
        int sum = 0;
        int num;

        for (int j = 0; j < 100; j++) {
            scanf("%d", &num);
            if (num == -1) break; // Assuming -1 is the end of the list
            l1[j] = num;
            sum += num;
        }

        if (sum > 1) {
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}
