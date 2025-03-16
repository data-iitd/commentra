#include <stdio.h>

#define MAX_SIZE 1001

void solve(int n) {
    int array[MAX_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d", &index);
        array[index]++;
    }

    int countMax = -1;
    for (int i = 1; i < MAX_SIZE; i++) {
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
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}

// <END-OF-CODE>
