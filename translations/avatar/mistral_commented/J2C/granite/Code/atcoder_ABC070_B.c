

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c > b) {
        printf("0\n");
        return 0;
    }

    if (a > d) {
        printf("0\n");
        return 0;
    }

    if (a < c) {
        int difference = (b < d)? b - c : d - c;
        printf("%d\n", difference);
        return 0;
    }

    int l[] = {a, b, c, d};
    int i;
    for (i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (l[i] > l[j]) {
                int temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }

    int difference = l[2] - l[1];
    printf("%d\n", difference);

    return 0;
}
