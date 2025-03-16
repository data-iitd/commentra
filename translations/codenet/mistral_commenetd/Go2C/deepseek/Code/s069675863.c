#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)math.MaxInt64
#define INF_BIT60 1LL << 60
#define INF_INT32 (int32_t)math.MaxInt32
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

char* ReadString();
int ReadInt();
int ReadInt2();
int ReadInt3();
int ReadInt4();
int64_t ReadInt64();
int* ReadIntSlice(int);
int64_t* ReadInt64Slice(int);
double ReadFloat64();
double* ReadFloat64Slice(int);
char* ReadRuneSlice();

char* ZeroPaddingRuneSlice(int, int);
char* PrintIntsLine(int*, int);
char* PrintInts64Line(int64_t*, int);
void PrintfDebug(char*, ...);
void PrintfBufStdout(char*, ...);

void init();
void main();
void make2DBooleanArray();
void updateDPX(int, int);
void updateDPY(int, int);

char S[8001];
int x, y;

bool dpx[8000][20000];
bool dpy[8000][20000];

void init() {
    // bufio.ScanWords <---> bufio.ScanLines
    // ReadString = newReadString(os.Stdin, bufio.ScanWords);
    // stdout = bufio.NewWriter(os.Stdout);
}

void main() {
    // Read a string from the standard input
    scanf("%s", S);

    // Parse two integers from the string and assign them to the variables x and y
    x = ReadInt();
    y = ReadInt();

    // Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
    make2DBooleanArray();

    // Iterate through the even indices of the F slice and update the dpx array accordingly
    for (int i = 0; i < strlen(S); i += 2) {
        updateDPX(i, S[i] - '0');
    }

    // Iterate through the odd indices of the F slice and update the dpy array accordingly
    for (int i = 1; i < strlen(S); i += 2) {
        updateDPY(i, S[i] - '0');
    }

    // Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
    if (dpx[strlen(S) / 2][x + 10000] && dpy[strlen(S) / 2][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// helper function to initialize a 2D boolean array
void make2DBooleanArray() {
    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));
}

// helper function to update dpx array
void updateDPX(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
        }
        if (j - val >= 2000 && index != 0) {
            dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
        }
    }
}

// helper function to update dpy array
void updateDPY(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
        }
        if (j - val >= 2000) {
            dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
        }
    }
}

char* ReadString() {
    static char buf[1000001];
    scanf("%s", buf);
    return buf;
}

int ReadInt() {
    return (int)readInt64();
}

int ReadInt2() {
    int a, b;
    scanf("%d %d", &a, &b);
    return a, b;
}

int ReadInt3() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    return a, b, c;
}

int ReadInt4() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    return a, b, c, d;
}

int64_t ReadInt64() {
    int64_t i;
    scanf("%lld", &i);
    return i;
}

int* ReadIntSlice(int n) {
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return a;
}

int64_t* ReadInt64Slice(int n) {
    int64_t* a = (int64_t*)malloc(n * sizeof(int64_t));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    return a;
}

double ReadFloat64() {
    return (double)readFloat64();
}

double readFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

double* ReadFloat64Slice(int n) {
    double* a = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    return a;
}

char* ReadRuneSlice() {
    static char buf[1000001];
    scanf("%s", buf);
    return buf;
}

char* ZeroPaddingRuneSlice(int n, int digitsNum) {
    char* sn = (char*)malloc(33 * sizeof(char));
    sprintf(sn, "%b", n);

    int residualLength = digitsNum - strlen(sn);
    if (residualLength <= 0) {
        return sn;
    }

    char* zeros = (char*)malloc(residualLength + 1);
    for (int i = 0; i < residualLength; i++) {
        zeros[i] = '0';
    }
    zeros[residualLength] = '\0';

    char* res = (char*)malloc(residualLength + strlen(sn) + 1);
    strcpy(res, zeros);
    strcat(res, sn);

    free(zeros);
    free(sn);
    return res;
}

char* PrintIntsLine(int* A, int n) {
    static char buf[1000001];
    buf[0] = '\0';
    for (int i = 0; i < n; i++) {
        char temp[20];
        sprintf(temp, "%d", A[i]);
        strcat(buf, temp);
        if (i != n - 1) {
            strcat(buf, " ");
        }
    }
    return buf;
}

char* PrintInts64Line(int64_t* A, int n) {
    static char buf[1000001];
    buf[0] = '\0';
    for (int i = 0; i < n; i++) {
        char temp[20];
        sprintf(temp, "%lld", A[i]);
        strcat(buf, temp);
        if (i != n - 1) {
            strcat(buf, " ");
        }
    }
    return buf;
}

void PrintfDebug(char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void PrintfBufStdout(char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

