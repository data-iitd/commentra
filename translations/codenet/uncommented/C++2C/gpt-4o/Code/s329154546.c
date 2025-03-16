#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define MAX_STRING_LENGTH 100 // Define a maximum length for strings
=======
#define MAX_STRING_LENGTH 100
#define MAX_STRINGS 100
>>>>>>> 98c87cb78a (data updated)

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
<<<<<<< HEAD
    char S[N][MAX_STRING_LENGTH]; // Array of strings

    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]); // Read each string
=======
    char S[MAX_STRINGS][MAX_STRING_LENGTH];
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
>>>>>>> 98c87cb78a (data updated)
    }

    // Sort the strings using qsort
    qsort(S, N, sizeof(S[0]), (int (*)(const void *, const void *)) strcmp);

    for (int i = 0; i < N; i++) {
<<<<<<< HEAD
        printf("%s", S[i]); // Print each string
=======
        printf("%s", S[i]);
>>>>>>> 98c87cb78a (data updated)
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
