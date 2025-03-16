#include <stdio.h>

<<<<<<< HEAD
#define N 100007

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    int tc, n, m, fl = 0;
    scanf("%d%d%d", &tc, &n, &m);
    
    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    
    for (int i = 1; i <= m; i++) {
        if (i * tc >= n && i * tc <= m) {
            printf("OK\n");
            fl = 1;
            break;
        }
    }
    
    if (fl == 0) {
        puts("NG");
    }
    
    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
//<END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
