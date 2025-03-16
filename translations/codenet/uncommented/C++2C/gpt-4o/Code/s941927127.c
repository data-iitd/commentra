#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(void) {
    char W[100]; // Assuming the maximum length of the string is 99 characters
    scanf("%s", W);
    
    size_t len = strlen(W);
    
    // Sort the string
    qsort(W, len, sizeof(char), compare);
    
    for (size_t i = 0; i < len; i += 2) {
        if (i + 1 >= len || W[i] != W[i + 1]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    
    return 0;
}

// <END-OF-CODE>
