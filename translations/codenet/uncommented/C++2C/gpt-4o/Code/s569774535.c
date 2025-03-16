#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    int ok = 1; // true
    while (ok) {
        ok = 0; // reset ok for this iteration
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                printf("%d\n", ans);
                return 0;
            } else {
                a[i] /= 2;
<<<<<<< HEAD
                ok = 1; // if we successfully divided, set ok to true
=======
                ok = 1; // set ok to true if we successfully divided
>>>>>>> 98c87cb78a (data updated)
            }
        }
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
