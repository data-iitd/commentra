#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

int n;
int a[MAX_N];
int s[MAX_N];
int s_count[MAX_N];

void set() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

bool isPossible(int k) {
    for (int i = 0; i < MAX_N; i++) {
        s_count[i] = 0; // Initialize the count array
    }
    
    int current = 0;
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        if (ai <= current) {
            if (k == 1) return false;
            while (s_count[ai] > 0) {
                s_count[ai]--;
                ai--;
            }
            int p = ai - 1;
            while (true) {
                if (p < 0) return false;
                s_count[p]++;
                if (s_count[p] == k) {
                    s_count[p] = 0; // Remove the entry
                    p--;
                } else {
                    break;
                }
            }
        }
        current = ai;
    }
    return true;
}

int main() {
    set();
    int ng = 0, ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
    return 0;
}

// <END-OF-CODE>
