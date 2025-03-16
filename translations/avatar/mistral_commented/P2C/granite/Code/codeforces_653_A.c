

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // Read the number of elements in the list
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));  // Allocate memory for the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Read the list of integers
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l[i] + 1 == l[j] && l[j] + 1 == l[k]) {  // Check if the next two elements are also in the list
                    printf("YES\n");  // If yes, print 'YES' and exit the program
                    return 0;
                }
            }
        }
    }
    printf("NO\n");  // If no, print 'NO' after the loop finishes
    return 0;
}

Translate the above C code to Java and end with comment "