#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int* a;

int isPossible(int k) {
    // Implement the logic to check if it's possible to arrange the array with k groups
    // This is a placeholder for the actual implementation
    return 0; // Placeholder return value
}

void solve() {
    // Implement the logic to find the maximum k such that it's possible to arrange the array into k groups
    int ng = 0;
    int ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
}

void set() {
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    char buffer[100000];
    scanf(" %[^\n]", buffer);
    char* token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        a[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    set();
    solve();
    free(a);
    return 0;
}

