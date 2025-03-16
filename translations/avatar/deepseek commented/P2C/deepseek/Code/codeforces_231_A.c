#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int l1[100], size = 0, sum = 0;
        while (scanf("%d", &l1[size]) != EOF && l1[size] != -1) {
            size++;
        }

        for (int j = 0; j < size; j++) {
            sum += l1[j];
        }

        if (sum > 1) {
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}
