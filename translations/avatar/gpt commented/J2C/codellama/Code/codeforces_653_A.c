#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Use try-with-resources to ensure Scanner and PrintWriter are closed automatically
    int n; 
    scanf("%d", &n); 
    int a[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
    } 
    int a_size = sizeof(a) / sizeof(a[0]); 
    for (int i = 0; i < a_size; i++) { 
        for (int j = i + 1; j < a_size; j++) { 
            if (a[i] == a[j]) { 
                a[j] = a[a_size - 1]; 
                a_size--; 
                j--; 
            } 
        } 
    } 
    qsort(a, a_size, sizeof(int), compare); 
    bool found = false; 
    for (int i = 0; i < a_size; i++) { 
        if (i + 1 < a_size && i + 2 < a_size) { 
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) { 
                found = true; 
            } 
        } 
    } 
    printf("%s\n", found ? "YES" : "NO"); 
    return 0; 
} 

int compare(const void *a, const void *b) { 
    return ( *(int*)a - *(int*)b ); 
} 

