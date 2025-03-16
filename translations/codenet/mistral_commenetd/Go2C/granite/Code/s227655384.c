
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a new Console instance
    Console con;
    // Read long lines from the standard input
    char* lines[4];
    for (int i = 0; i < 4; i++) {
        lines[i] = (char*)malloc(1000 * sizeof(char));
        fgets(lines[i], 1000, stdin);
    }
    // Split the second line into an integer slice
    char* a[1000];
    int a_count = 0;
    char* token = strtok(lines[1], " ");
    while (token!= NULL) {
        a[a_count++] = token;
        token = strtok(NULL, " ");
    }
    // Iterate through the integer slice and add each integer to the map
    int m[100000];
    int m_count = 0;
    for (int i = 0; i < a_count; i++) {
        int n = atoi(a[i]);
        int found = 0;
        for (int j = 0; j < m_count; j++) {
            if (m[j] == n) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[m_count++] = n;
        }
    }

    // Read integers from the fourth line and add them to the map if they are not already present
    char* b[1000];
    int b_count = 0;
    token = strtok(lines[3], " ");
    while (token!= NULL) {
        b[b_count++] = token;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < b_count; i++) {
        int n = atoi(b[i]);
        int found = 0;
        for (int j = 0; j < m_count; j++) {
            if (m[j] == n) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[m_count++] = n;
        }
    }

    // Extract the unique integers from the map and store them in a slice
    int result[200000];
    int result_count = 0;
    for (int i = 0; i < m_count; i++) {
        result[result_count++] = m[i];
    }

    // Sort the result slice in ascending order
    qsort(result, result_count, sizeof(int), compare);

    // Iterate through the sorted result slice and print each integer to the standard output
    for (int j = 0; j < result_count; j++) {
        con.Printf("%d\n", result[j]);
    }

    // Free the allocated memory for the lines and tokens
    for (int i = 0; i < 4; i++) {
        free(lines[i]);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 

