#include <stdio.h>

int main() {
    int N, ans, i, count;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    i = 0;
    ans = 0;
    count = 0;
    while (i + 1 < N) { // Changed condition to avoid accessing out of bounds
        if (A[i] == A[i + 1]) {
            count++;
            if (count % 2 != 0)
                ans++;
        } else {
            count = 0;
        }
        i++;
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
