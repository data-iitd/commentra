#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an input line (not used in the logic)
    scanf("%*[^\n]");
    
    // Read a line of integers, split by spaces, and convert them to a list of integers
    int a[100000];
    int i = 0;
    char *p = (char *)malloc(100000 * sizeof(char));
    scanf("%s", p);
    while (p[i]!= '\0') {
        a[i] = p[i] - '0';
        i++;
    }
    
    // Sort the list of integers in ascending order
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (a[j] > a[k]) {
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
    }
    
    // Iterate through the sorted list starting from the second element
    for (int j = 1; j < i; j++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[j]!= a[j - 1] && a[j] < a[j - 1] * 2) {
            // If the condition is met, print 'YES'
            printf("YES");
            return 0;
        }
    }
    
    // If no such pair is found, print 'NO'
    printf("NO");
    return 0;
}

