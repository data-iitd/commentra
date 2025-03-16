#include <stdio.h>
#include <stdlib.h>

// Function to read input as a list of integers
int* _input() {
    int n, m;
    scanf("%d %d", &n, &m);
    int* lst = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    return lst;
}

// Function to calculate the number of pairs of elements in the list 'lst'
// that have a smaller frequency than the current element
int countPairs(int* lst, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (lst[i] == lst[j]) {
                freq++;
            }
        }
        res += freq * (freq - 1) / 2;
    }
    return res;
}

// Main function
int main() {
    int n, m;
    int* lst = _input();
    n = lst[0];
    m = lst[1];
    int res = countPairs(lst + 2, n);
    printf("%d\n", res);
    return 0;
}

