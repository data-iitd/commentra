#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int result = (x + y - 3) + ((y - x) % 3 > 0);
    result = result > 0 ? result : 0;
    printf("%d\n", result);

    return 0;
}

int num_inp() {
    int input;
    scanf("%d", &input);
    return input;
}

int* arr_inp() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int* sp_inp() {
    int* arr = (int*)malloc(2 * sizeof(int));
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

char* str_inp() {
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

