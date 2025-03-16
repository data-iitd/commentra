#include <stdio.h>
#include <stdlib.h>

int next_int() {
    int num;
    scanf("%d", &num);
    return num;
}

int* next_ints() {
    int* arr = (int*)malloc(100 * sizeof(int)); // Assuming a maximum of 100 integers
    char ch;
    int i = 0;
    while (scanf("%d%c", &arr[i], &ch) == 2) {
        if (ch == '\n') break;
        i++;
    }
    return arr;
}

int main() {
    int n = next_int();
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) & 1) {
            t += 1;
        }
    }
    printf("%.10f\n", (double)t / n);
    return 0;
}
