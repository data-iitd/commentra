#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && i + 2 < n) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true;
            }
        }
    }
    printf("%s\n", found? "YES" : "NO");
    return 0;
}
