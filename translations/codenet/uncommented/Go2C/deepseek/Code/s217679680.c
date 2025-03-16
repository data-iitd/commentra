#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* scanArrayInt() {
    int* ret = (int*)malloc(100 * sizeof(int)); // Assuming the array size won't exceed 100 for simplicity
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    char* token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        ret[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return ret;
}

int main() {
    int* arr = scanArrayInt();
    int a = arr[0], b = arr[1];
    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    printf("%d\n", tap);
    free(arr);
    return 0;
}
