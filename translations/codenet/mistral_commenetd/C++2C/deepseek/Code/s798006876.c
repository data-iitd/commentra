#include <stdio.h>

#define MAX_N 1000 // maximum size of the array

int data[MAX_N]; // array to store input data

int main() {
    int m, nmi, nma; // m: number of elements in the array, nmi and nma: indices of the subarray to find the maximum difference in
    while (scanf("%d %d %d", &m, &nmi, &nma) != EOF && nmi != 0) { // read input until EOF or nmi is 0
        for (int i = 0; i < m; i++) scanf("%d", &data[i]); // read input data into the array
        int ma = 0; // initialize maximum difference to 0
        int ans = 0; // initialize answer to 0
        for (int i = nmi - 1; i < nma; i++) { // iterate through the subarray
            if (ma <= data[i] - data[i + 1]) { // if current difference is greater than the previous maximum difference
                ans = i + 1; // update answer with the index of the current element
                ma = data[i] - data[i + 1]; // update maximum difference with the current difference
            }
        }
        printf("%d\n", ans); // print the answer
    }
