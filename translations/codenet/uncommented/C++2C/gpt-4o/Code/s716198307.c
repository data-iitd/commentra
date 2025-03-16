#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n, a[100];
    double avg = 0, s, ans = 0;
<<<<<<< HEAD
    
=======
>>>>>>> 98c87cb78a (data updated)
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        avg += a[i];
    }
<<<<<<< HEAD
    
    avg /= n;
    s = fabs(a[0] - avg);
    
=======
    avg /= n;
    s = fabs(a[0] - avg);
>>>>>>> 98c87cb78a (data updated)
    for (int i = 1; i < n; i++) {
        if (s > fabs(a[i] - avg)) {
            s = fabs(a[i] - avg);
            ans = i;
        }
    }
<<<<<<< HEAD
    
=======
>>>>>>> 98c87cb78a (data updated)
    printf("%d\n", (int)ans);
    return 0;
}

// <END-OF-CODE>
