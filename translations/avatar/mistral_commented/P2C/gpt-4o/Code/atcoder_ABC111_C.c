#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100003

int main() {
    int n;
    // Take the number of elements in the list from user input
    scanf("%d", &n);

    // Initialize an array 'x' to store the input elements
    int *x = (int *)malloc(n * sizeof(int));
    
    // Read the input elements into the array 'x'
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    // Initialize two arrays 'a' and 'b' to store even and odd elements respectively
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int count_a = 0, count_b = 0;

    // Iterate through the array 'x' and append even and odd elements to their respective arrays
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[count_a++] = x[i];
        } else {
            b[count_b++] = x[i];
        }
    }

    // Initialize two arrays 'cnta' and 'cntb' to store the count of each element in arrays 'a' and 'b' respectively
    int cnta[MAX_SIZE] = {0};
    int cntb[MAX_SIZE] = {0};

    // Initialize variables to store the elements with maximum count in arrays 'a' and 'b'
    int vala = 0, valb = 0;
    int maxCnta = 0, maxCntb = 0;
    int vala1 = 0, valb1 = 0;
    int maxCnta1 = 0, maxCntb1 = 0;

    // Count occurrences in array 'a'
    for (int i = 0; i < count_a; i++) {
        cnta[a[i]]++;
    }

    // Find the element with maximum count in array 'a'
    for (int i = 0; i < count_a; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }

    // Find the second element with maximum count in array 'a'
    for (int i = 0; i < count_a; i++) {
        if (maxCnta1 < cnta[a[i]] && a[i] != vala) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Count occurrences in array 'b'
    for (int i = 0; i < count_b; i++) {
        cntb[b[i]]++;
    }

    // Find the element with maximum count in array 'b'
    for (int i = 0; i < count_b; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    // Find the second element with maximum count in array 'b'
    for (int i = 0; i < count_b; i++) {
        if (maxCntb1 < cntb[b[i]] && b[i] != valb) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Check if 'vala' and 'valb' are the same or not
    if (valb != vala) {
        // If they are not the same, calculate the sum of counts of all elements except 'vala' and 'valb'
        int res = 0;
        for (int i = 0; i < count_a; i++) {
            if (a[i] != vala) {
                res++;
            }
        }
        for (int i = 0; i < count_b; i++) {
            if (b[i] != valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        // If 'vala' and 'valb' are the same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
        for (int i = 0; i < count_a; i++) {
            if (a[i] != vala) {
                resa++;
            }
            if (a[i] != vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < count_b; i++) {
            if (b[i] != valb) {
                resb++;
            }
            if (b[i] != valb1) {
                resb1++;
            }
        }
        printf("%d\n", (resa + resb1 < resa1 + resb) ? (resa + resb1) : (resa1 + resb));
    }

    // Free allocated memory
    free(x);
    free(a);
    free(b);

    return 0;
}
// <END-OF-CODE>
