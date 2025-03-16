#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
=======
#define REP(i,n) for(int i=0;i<n;i++)

>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
<<<<<<< HEAD
    
    for (int i = 0; i < n; i++) {
=======
    REP(i, n) {
>>>>>>> 98c87cb78a (data updated)
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), compare);
    
<<<<<<< HEAD
    for (int i = 0; i < n - 1; i++) {
=======
    REP(i, n - 1) {
>>>>>>> 98c87cb78a (data updated)
        if (a[i] == a[i + 1]) {
            printf("NO\n");
            free(a);
            return 0;
        }
    }
    
    printf("YES\n");
    free(a);
    
    return 0;
}

// <END-OF-CODE>
