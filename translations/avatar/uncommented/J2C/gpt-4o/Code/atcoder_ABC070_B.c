#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d ? b : d) - c);
    } else {
        int values[4] = {a, b, c, d};
        // Sort the array
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (values[i] > values[j]) {
                    int temp = values[i];
                    values[i] = values[j];
                    values[j] = temp;
                }
            }
        }
        printf("%d\n", values[2] - values[1]);
    }

    return 0;
}

// <END-OF-CODE>
