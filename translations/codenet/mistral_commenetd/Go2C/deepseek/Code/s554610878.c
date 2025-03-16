#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000000007

char* getString() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int getInt() {
    char* line = getString();
    int value = atoi(line);
    free(line);
    return value;
}

int main() {
    char* week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char* s = getString();
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        fprintf(stderr, "Invalid day of the week\n");
        return 1;
    }
    printf("%d\n", 7 - index);
    return 0;
}

int abs(int num) {
    return num < 0 ? -num : num;
}

int pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int min(int nums[], int size) {
    int min = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int max(int nums[], int size) {
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int strSearch(char* slice[], int size, char* str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(slice[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int calcMod(int num) {
    return num % MOD;
}
