
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int array[1001] = {0};
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d", &index);
        array[index]++;
    }
    int countMax = -1;
    for (int i = 1; i < 1001; i++) {
        if (countMax < array[i]) {
            countMax = array[i];
        }
    }
    if (n % 2 == 0) {
        if (countMax <= n / 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        if (countMax <= n / 2 + 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
