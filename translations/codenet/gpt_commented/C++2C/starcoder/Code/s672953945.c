#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main() {
    // Declare a vector to store strings and variables for input
    int N, L;
    char **v;

    // Read the number of strings (N) and the length of strings (L)
    scanf("%d %d", &N, &L);

    // Input N strings from the user and store them in the vector
    v = (char**)malloc(N * sizeof(char*));
    for(int i = 0; i < N; i++) {
        v[i] = (char*)malloc(L * sizeof(char));
        scanf("%s", v[i]);
    }

    // Sort the vector of strings in lexicographical order
    qsort(v, N, sizeof(char*), (int(*)(const void*, const void*))strcmp);

    // Output the sorted strings
    for(int i = 0; i < N; i++) {
        printf("%s", v[i]); // Print each string in the sorted order
    }
    printf("\n"); // Print a newline at the end
}

