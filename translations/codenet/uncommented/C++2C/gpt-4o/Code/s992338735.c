#include <stdio.h>

int main() {
    int N, S;

    while (scanf("%d", &N) == 1 && N > 0) {
        int M = -1, m = 1001, addup = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &S);
            addup += S;
            if (S > M) M = S;
            if (S < m) m = S;
        }
<<<<<<< HEAD

=======
        
>>>>>>> 98c87cb78a (data updated)
        printf("%d\n", (addup - M - m) / (N - 2));
    }

    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
