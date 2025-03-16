#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE (1e5 * 2) + 13 // Define the size of the count array

int main(){
    int n, k;
    scanf("%d %d", &n, &k); // Read the number of elements and the threshold k
    
    // Count occurrences of each integer
    int cnt[SIZE];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    // Filter non-zero counts and store them in vector a
    int a[SIZE];
    int m = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[m] = cnt[i];
            m++;
        }
    }
    
    // Sort the vector a in ascending order
    qsort(a, m, sizeof(int), compare);
    
    // Calculate the sum of the smallest k counts in vector a
    int ans = 0;
    int m = m - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    
    // Output the result
    printf("%d\n", ans);
    
    return 0;
}

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

