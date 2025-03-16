#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold a string
typedef struct {
    char *X;
} Data;

// Function to compare two Data structures for sorting
int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

// Utility function to print multiple values with a newline
void out(int N, int L, Data *s) {
    // Uncomment to print values
    // printf("%d %d\n", N, L);
    // for (int i = 0; i < N; i++) {
<<<<<<< HEAD
    //     printf("%s\n", s[i].X);
    // }
=======
    //     printf("%s ", s[i].X);
    // }
    // printf("\n");
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    Data *s = malloc(N * sizeof(Data));
    for (int i = 0; i < N; i++) {
        s[i].X = malloc(100 * sizeof(char)); // Assuming max string length is 99
        scanf("%s", s[i].X);
    }

    out(N, L, s);
    
    // Sort the array of Data
    qsort(s, N, sizeof(Data), compare);
    
    out(N, L, s);

    // Concatenate the strings
    char *ans = malloc(N * 100 * sizeof(char)); // Assuming max string length is 99
    ans[0] = '\0'; // Initialize the string
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }
    
    printf("%s\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(s[i].X);
    }
    free(s);
    free(ans);

    return 0;
}

// <END-OF-CODE>
