
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

// Define constants for general purpose usage
#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807LL
#define NIL -1

// Function to read a string
char* ReadString() {
    int bufSize = 1024;
    char* buf = (char*)malloc(sizeof(char) * bufSize);
    fgets(buf, bufSize, stdin);
    char* str = (char*)malloc(sizeof(char) * strlen(buf));
    strcpy(str, buf);
    free(buf);
    return str;
}

// Function to read an integer
int ReadInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read two integers
int* ReadInt2() {
    int* a = (int*)malloc(sizeof(int) * 2);
    scanf("%d %d", &a[0], &a[1]);
    return a;
}

// Function to read three integers
int* ReadInt3() {
    int* a = (int*)malloc(sizeof(int) * 3);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    return a;
}

// Function to read four integers
int* ReadInt4() {
    int* a = (int*)malloc(sizeof(int) * 4);
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    return a;
}

// Function to read an integer64
long long ReadInt64() {
    long long n;
    scanf("%lld", &n);
    return n;
}

// Function to read two integer64 values
long long* ReadInt64_2() {
    long long* a = (long long*)malloc(sizeof(long long) * 2);
    scanf("%lld %lld", &a[0], &a[1]);
    return a;
}

// Function to read three integer64 values
long long* ReadInt64_3() {
    long long* a = (long long*)malloc(sizeof(long long) * 3);
    scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
    return a;
}

// Function to read four integer64 values
long long* ReadInt64_4() {
    long long* a = (long long*)malloc(sizeof(long long) * 4);
    scanf("%lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3]);
    return a;
}

// Function to read a string
char* ReadString() {
    int bufSize = 1024;
    char* buf = (char*)malloc(sizeof(char) * bufSize);
    fgets(buf, bufSize, stdin);
    char* str = (char*)malloc(sizeof(char) * strlen(buf));
    strcpy(str, buf);
    free(buf);
    return str;
}

// Function to read a rune slice
rune* ReadRuneSlice(int n) {
    rune* b = (rune*)malloc(sizeof(rune) * n);
    for (int i = 0; i < n; i++) {
        b[i] = ReadInt64();
    }
    return b;
}

// Function to read a float64
double ReadFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

// Function to read a float64 slice
double* ReadFloat64Slice(int n) {
    double* b = (double*)malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        b[i] = ReadFloat64();
    }
    return b;
}

// Function to read a rune slice
rune* ReadRuneSlice() {
    return []rune(ReadString()) // Convert input string to rune slice
}

// Function to print integers separated by a space
void PrintIntsLine(int... A) {
    printf("%d", A...); // Print integers separated by a space
}

// Function to print integers separated by a space
void PrintIntsLine(int... A) {
    printf("%d", A...); // Print integers separated by a space
}

// Function to print integers separated by a space
void PrintIntsLine(int... A) {
    printf("%d", A...); // Print integers separated by a space
}

// Function to print integers separated by a space
void PrintIntsLine(int64... A) {
    printf("%lld", A...); // Print integers separated by a space
}

// Function to print integers separated by a space
void PrintInts64Line(int64... A) {
    printf("%lld", A...); // Print integers separated by a space
}

// Function to print a string
void PrintfDebug(string format,...a) {
    fmt.Fprintf(os.Stderr, format, a...) // Print debug information to stderr
}

// Function to print a string
void PrintfBufStdout(string format,...a) {
    fmt.Fprintf(stdout, format, a...) // Printf to stdout
}

// Function to read a string
string ReadString() {
    bufSize := 1024
    buf := make([]byte, bufSize) // Create a buffer
    fgets(buf, bufSize, stdin) // Read a string
    str := string(buf) // Convert to string
    free(buf) // Free the buffer
    return str
}

// Function to read an integer
int ReadInt() {
    int n;
    scanf("%d", &n) // Read an integer
    return n
}

// Function to read two integers
int* ReadInt2() {
    int a, b;
    scanf("%d %d", &a, &b) // Read two integers
    return []int{a, b}
}

// Function to read three integers
int* ReadInt3() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c) // Read three integers
    return []int{a, b, c}

// Function to read four integers
int* ReadInt4() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d) // Read four integers
    return []int{a, b, c, d}

// Function to read a string
string ReadString() {
    bufSize := 1024
    buf := make([]byte, bufSize) // Create a buffer
    fgets(buf, bufSize, stdin) // Read a string
    str := string(buf) // Convert to string
    free(buf) // Free the buffer
    return str
}

// Function to read a rune
rune ReadRunes() {
    return []rune(ReadString()) // Convert input string to rune slice
    rune* ReadRunesLine(rune... r) {
    buf := make([]rune, 1024) // Create a buffer
    fgets(buf, bufSize, stdin) // Read a string
    str := string(buf) // Convert to string
    free(buf) // Free the buffer
    return str
}

// Function to read a float64
double ReadFloat64() {
    double f;
    scanf("%lf", &f) // Read a float64
    return f
}

// Function to read a float64 slice
float64* ReadFloat64Slice(int n) {
    float64Slice(n) // Convert to float64 slice
    float64* ReadFloat64Slice(n) // Convert to float64 slice
    return []float64(n)
}

// Function to read a rune slice
rune* ReadRuneSlice() {
    return []rune(ReadString()) // Convert input string to rune slice
    return []rune(ReadRuneSlice() // Convert to rune slice
    free(rune) // Free the buffer
    return rune
}

// Function to read a string
string ReadString() {
    return string(ReadString()) // Convert input string to string
}

// Function to read an integer
int ReadInt() {
    int n;
    scanf("%d", &n) // Read an integer
    return n
}

// Function to read two integers
int* ReadInt2() {
    int a, b;
    scanf("%d %d", &a, &b) // Read two integers
    return []int{a, b}
}

// Function to read three integers
int* ReadInt3() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c) // Read three integers
    return []int{a, b, c}
}
// Function to read four integers
int* ReadInt4() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d) // Read four integers
    return []int{a, b, c, d}

// Function to read a string
string ReadString() {
    return string(ReadString()) // Convert input string to string
    str := string(ReadRunesLine(rune... r) {
    return []rune(ReadRuneSlice() // Convert to rune slice
    return r
}

// Function to read a float64
float64 ReadFloat64() {
    float64_slice := make([]float64, 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000