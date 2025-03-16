#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int main() {
    int n;
    scanf("%d", &n);
    
    int ara[MAX_SIZE];
    int count[MAX_SIZE] = {0}; // To count occurrences of each number
    int max_count = 0;

    // Read input and count occurrences
    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        count[ara[i]]++;
        if (count[ara[i]] > max_count) {
            max_count = count[ara[i]];
        }
    }

    // Find the first number with the maximum count
    for (int i = 0; i < n; i++) {
        if (count[ara[i]] == max_count) {
            printf("%d\n", ara[i]);
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
