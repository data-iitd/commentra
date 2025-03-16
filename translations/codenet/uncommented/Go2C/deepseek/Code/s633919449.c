#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

int getInt();
int* getIntArray(int n);
char* getString();
char** getStringArray(int n);
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int nums[], int size);
int max(int nums[], int size);
int strSearch(char* a[], char* b);
void printIntArray(int array[], int size);
int calcMod(int x);
char* reverse(char* s);
int isPrime(int n);
int contains(int s[], int size, int e);
int* makeRange(int min, int max);
int** powerset2(int nums[], int size, int* resultSize);
int* copyAndAppend(int nums[], int size, int n);
int calcGcd(int x, int y);
int* getDivisor(int n);

typedef struct {
    int* data;
    int size;
} intHeap;

void intHeapInit(intHeap* h);
void intHeapPush(intHeap* h, int n);
int intHeapPop(intHeap* h);
int factMod(int n);
int combinationMod(int n, int k);
int* primeFactors(int n);

int main() {
    int N = getInt();

    switch (N % 10) {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            printf("hon\n");
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            printf("pon\n");
            break;
        case 3:
            printf("bon\n");
            break;
    }

    return 0;
}

int getInt() {
    char buf[INITIAL_BUF_SIZE];
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        return atoi(buf);
    }
    return -1; // Error
}

int* getIntArray(int n) {
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

char* getString() {
    char buf[INITIAL_BUF_SIZE];
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        char* str = (char*)malloc(strlen(buf) + 1);
        strcpy(str, buf);
        return str;
    }
    return NULL; // Error
}

char** getStringArray(int n) {
    char** array = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

int abs(int a) {
    return (int)fabs(a);
}

int pow(int p, int q) {
    return (int)pow(p, q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int nums[], int size) {
    if (size == 0) {
        return -1; // Error
    }
    int res = nums[0];
    for (int i = 0; i < size; i++) {
        res = (int)fmin(res, nums[i]);
    }
    return res;
}

int max(int nums[], int size) {
    if (size == 0) {
        return -1; // Error
    }
    int res = nums[0];
    for (int i = 0; i < size; i++) {
        res = (int)fmax(res, nums[i]);
    }
    return res;
}

int strSearch(char* a[], char* b) {
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
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
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
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

int contains(int s[], int size, int e) {
    for (int i = 0; i < size; i++) {
        if (s[i] == e) {
            return 1;
        }
    }
    return 0;
}

int* makeRange(int min, int max) {
    int* a = (int*)malloc((max - min + 1) * sizeof(int));
    for (int i = 0; i <= max - min; i++) {
        a[i] = min + i;
    }
    return a;
}

int** powerset2(int nums[], int size, int* resultSize) {
    *resultSize = 1 << size;
    int** result = (int**)malloc(*resultSize * sizeof(int*));
    for (int i = 0; i < *resultSize; i++) {
        result[i] = (int*)malloc((size + 1) * sizeof(int));
        result[i][0] = 0;
        int index = 1;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                result[i][index++] = nums[j];
            }
        }
    }
    return result;
}

int* copyAndAppend(int nums[], int size, int n) {
    int* dst = (int*)malloc((size + 1) * sizeof(int));
    memcpy(dst, nums, size * sizeof(int));
    dst[size] = n;
    return dst;
}

int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

int* getDivisor(int n) {
    int* divisor = (int*)malloc(100 * sizeof(int)); // Assuming max 100 divisors
    int count = 0;
    divisor[count++] = 1;
    if (n != 1) {
        divisor[count++] = n;
    }

    int sqrtN = (int)sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor[count++] = i;
            if (i != n / i) {
                divisor[count++] = n / i;
            }
        }
    }

    return divisor;
}

void intHeapInit(intHeap* h) {
    h->data = (int*)malloc(INITIAL_BUF_SIZE * sizeof(int));
    h->size = 0;
}

void intHeapPush(intHeap* h, int n) {
    if (h->size == MAX_BUF_SIZE) {
        // Handle overflow
        return;
    }
    h->data[h->size++] = n;
    int i = h->size - 1;
    while (i > 0 && h->data[i] > h->data[(i - 1) / 2]) {
        int temp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int intHeapPop(intHeap* h) {
    if (h->size == 0) {
        return -1; // Error
    }
    int root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->data[child] < h->data[child + 1]) {
            child++;
        }
        if (h->data[i] >= h->data[child]) {
            break;
        }
        int temp = h->data[i];
        h->data[i] = h->data[child];
        h->data[child] = temp;
        i = child;
    }
    return root;
}

int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = calcMod(value * n);
    }
    return value;
}

int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, MOD - 2);
    int factNKR = powMod(factNK, MOD - 2);
    return calcMod(factN * calcMod(factKR * factNKR));
}

int* primeFactors(int n) {
    int* factors = (int*)malloc(100 * sizeof(int)); // Assuming max 100 factors
    int count = 0;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            factors[count++] = i;
            n /= i;
        } else {
            i++;
        }
    }
    if (n > 1) {
        factors[count++] = n;
    }
    return factors;
}

