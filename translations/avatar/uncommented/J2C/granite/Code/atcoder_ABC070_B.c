
#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d)? b : d - c);
    } else {
        int arr[4] = {a, b, c, d};
        int min = arr[0];
        for (int i = 1; i < 4; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        printf("%d\n", min - arr[1]);
    }
    return 0;
}
// END-OF-CODE