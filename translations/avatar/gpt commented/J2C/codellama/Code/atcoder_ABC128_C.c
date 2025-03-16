#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int main() { 
    // Initialize a Scanner to read input from the console
    int N, M; 
    scanf("%d %d", &N, &M); 
    int a[N]; 
    for (int i = 0; i < N; i++) { 
        a[i] = 0; 
    } 
    for (int i = 0; i < M; i++) { 
        int k; 
        scanf("%d", &k); 
        for (int j = 0; j < k; j++) { 
            int s; 
            scanf("%d", &s); 
            s--; 
            a[s] |= (1 << i); 
        } 
    } 
    int p = 0; 
    for (int i = 0; i < M; i++) { 
        int x; 
        scanf("%d", &x); 
        p |= (x << i); 
    } 
    int ans = 0; 
    for (int s = 0; s < (1 << N); s++) { 
        int t = 0; 
        for (int i = 0; i < N; i++) { 
            if (((s >> i) & 1) == 1) { 
                t ^= a[i]; 
            } 
        } 
        if (p == t) { 
            ans++; 
        } 
    } 
    printf("%d\n", ans); 
    return 0; 
} 
