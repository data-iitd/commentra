#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == curr + 1) curr++;
    }

    if(curr > 0) {
        printf("%d\n", n - curr);
    } else {
        printf("-1\n");
    }

    free(a); // Free the allocated memory
    return 0;
}

/* <END-OF-CODE> */
