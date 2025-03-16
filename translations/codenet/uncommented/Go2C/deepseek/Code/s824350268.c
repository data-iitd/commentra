#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007

int getInt() {
    int value;
    scanf("%d", &value);
    return value;
}

char* getString() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    int result = 1;
    for (int i = 0; i < q; i++) {
        result *= p;
    }
    return result;
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

int min(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < res) {
            res = nums[i];
        }
    }
    return res;
}

int max(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > res) {
            res = nums[i];
        }
    }
    return res;
}

int strSearch(char* a[], int size, char* b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
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

int calcMod(int x) {
    return x % MOD;
}

char* reverse(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int N = getInt();
    int sqrtN = (int)sqrt(N);

    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }

    printf("%d\n", min);
    return 0;
}
