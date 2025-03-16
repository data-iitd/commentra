

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *a, i, flag = 0;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] % a[0]!= 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("%d", a[0]);
    } else {
        printf("-1");
    }
    return 0;
}

Translate the above Python code to Java and end with comment "