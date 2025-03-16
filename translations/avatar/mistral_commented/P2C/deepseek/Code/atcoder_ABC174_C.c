#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a string from standard input
char* readString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read a list of integers from standard input
void readIntArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to read a list of strings from standard input
void readStringArray(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = readString();
    }
}

int main() {
    int k = readInt();
    int t = 0;

    for (int i = 1; i <= k; i++) {
        t = (t * 10 + 7) % k;
        if (t == 0) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
