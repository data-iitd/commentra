#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* getIntArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int* getInt2DArray(int m, int n) {
    int* arr = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i * n + j]);
        }
    }
    return arr;
}

char* getString() {
    char* str = (char*)malloc(1000 * sizeof(char));
    scanf("%s", str);
    return str;
}

char** getStringArray(int n) {
    char** arr = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(1000 * sizeof(char));
        scanf("%s", arr[i]);
    }
    return arr;
}

char** getString2DArray(int m, int n) {
    char** arr = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        arr[i] = (char*)malloc(1000 * sizeof(char));
        for (int j = 0; j < n; j++) {
            scanf("%s", arr[i] + j * 1000);
        }
    }
    return arr;
}

void sortIntArray(int* arr, int n) {
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))compare);
}

void sortIntReverseArray(int* arr, int n) {
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))reverseCompare);
}

int absValue(int x) {
    return x < 0 ? -x : x;
}

int modPow(int a, int n, int m) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int modInv(int a, int p) {
    if (a == 1) {
        return 1;
    }
    return p - modInv(p % a, p) * (p / a) % p;
}

int* modFactorial(int n) {
    int* frac = (int*)malloc((n + 1) * sizeof(int));
    frac[0] = 1;
    for (int i = 1; i <= n; i++) {
        frac[i] = i * frac[i - 1] % MOD;
    }
    return frac;
}

int modCombination(int n, int r) {
    int* frac = modFactorial(n);
    return (frac[n] / ((frac[n - r] * frac[r]) % MOD)) % MOD;
}

void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntArray(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(a);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int reverseCompare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    solve();
    return 0;
}
