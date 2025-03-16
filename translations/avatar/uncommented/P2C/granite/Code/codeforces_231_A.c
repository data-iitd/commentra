
#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l1[3];
        scanf("%d %d %d", &l1[0], &l1[1], &l1[2]);
        if (l1[0] + l1[1] + l1[2] > 1) {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
// END-OF-CODE