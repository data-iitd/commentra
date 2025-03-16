
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 
#include <stdint.h> 

#define MOD 1000000007 

typedef struct { 
    int n; 
    int* par; 
    int* rank; 
} UnionFindTree; 

void doIt() { 
    // Step 1: Read the input number of elements (n) and create a UnionFindTree instance.
    int n; 
    scanf("%d", &n); 
    UnionFindTree utf = (UnionFindTree) { 
        .n = n, 
        .par = (int*) malloc(n * sizeof(int)), 
        .rank = (int*) malloc(n * sizeof(int)) 
    }; 
    for (int i = 0; i < n; i++) { 
        utf.par[i] = i; 
        utf.rank[i] = 0; 
    } 
    
    // Step 2: Read the number of operations (m) and iterate through each operation.
    int m; 
    scanf("%d", &m); 
    for (int i = 0; i < m; i++) { 
        // Step 3: For each operation, read the two elements (x and y) and the operation type (z).
        int x, y, z; 
        scanf("%d %d %d", &x, &y, &z); 
        x--; 
        y--; 
        
        // Step 4: Perform the union operation on the elements x and y.
        unite(utf, x, y); 
    } 
    
    // Step 5: Count the number of connected components in the UnionFindTree and print the result.
    int cnt = 0; 
    for (int i = 0; i < n; i++) { 
        if (utf.par[i] == i) { 
            cnt++; 
        } 
    } 
    printf("%d\n", cnt); 
} 

void unite(UnionFindTree* utf, int x, int y) { 
    x = find(utf, x); 
    y = find(utf, y); 
    if (x == y) return; 
    if (utf->rank[x] < utf->rank[y]) { 
        utf->par[x] = y; 
    } else { 
        utf->par[y] = x; 
        if (utf->rank[x] == utf->rank[y]) utf->rank[x]++; 
    } 
} 

int find(UnionFindTree* utf, int x) { 
    if (utf->par[x] == x) { 
        return x; 
    } else { 
        return utf->par[x] = find(utf, utf->par[x]); 
    } 
} 

bool same(UnionFindTree* utf, int x, int y) { 
    return find(utf, x) == find(utf, y); 
} 

int main() { 
    doIt(); 
    return 0; 
} 

