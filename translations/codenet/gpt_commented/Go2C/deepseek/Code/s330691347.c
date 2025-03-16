#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
    char X[100];
} Data;

// Datas is a array of Data.
typedef Data Datas[100000];

// compare function for qsort
int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    Datas s;

    // Read N strings into the array s
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i].X);
    }

    // Sort the array of Data entries
    qsort(s, N, sizeof(Data), compare);

    // Concatenate all strings in the sorted array into a single result
    char ans[100001];
    ans[0] = '\0'; // Initialize the result string
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X); // Append each string to ans
    }
    printf("%s\n", ans); // Print the concatenated result

    return 0;
}
