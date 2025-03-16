
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for large prime numbers used in modular arithmetic.
#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// Global variable for debug mode.
int DEBUG = 0;

// -----------------------------------------------------------------------------
// IO helper functions

// Returns next token from input. It must be initialized by SetInput() before the first call.
char* nextToken() {
    static char buf[1000000];
    static char *p = buf;
    if (p >= buf + strlen(buf)) {
        fgets(buf, sizeof(buf), stdin);
        p = buf;
    }
    while (*p && isspace(*p)) {
        p++;
    }
    char *start = p;
    while (*p &&!isspace(*p)) {
        p++;
    }
    char *end = p;
    while (end > start && isspace(end[-1])) {
        end--;
    }
    *end = '\0';
    return start;
}

// Holds a buffer for output. It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
FILE *OutputBuffer = NULL;
FILE *OutputWriter = NULL;

// Set IO functions for interactive input/output.
void SetInteractive(FILE *w, FILE *r) {
    SetUnbufferedInput(r);
    OutputBuffer = NULL;
    OutputWriter = w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(FILE *w) {
    OutputBuffer = fopen("/dev/null", "w");
    OutputWriter = OutputBuffer;
}

// Flushes OutputBuffer
void Flush() {
    if (OutputBuffer!= NULL) {
        fclose(OutputBuffer);
    }
}

// Returns true if c is a white space
int IsSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case'':
            return 1;
    }
    return 0;
}

int IsNewLine(char c) {
    switch (c) {
        case '\n':
        case '\r':
            return 1;
    }
    return 0;
}

// Setup nextToken with input buffer.
void SetInput(FILE *r) {
    setbuf(r, NULL);
    char buf[1000000];
    char *b = buf;
    char *i = buf;

    char c;
    while (1) {
        c = fgetc(r);
        if (c == EOF) {
            break;
        }
        if (IsSpace(c)) {
            continue;
        }
        if (IsNewLine(c)) {
            *i = '\0';
            i = buf;
            if (nextInt() == EOF) {
                break;
            }
            continue;
        }
        *i = c;
        i++;
    }
    *i = '\0';
    nextToken = (char*(*)())nextInt;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(FILE *r) {
    setbuf(r, NULL);
    char buf[1000000];
    char *b = buf;
    char *i = buf;

    char c;
    while (1) {
        c = fgetc(r);
        if (c == EOF) {
            break;
        }
        if (IsSpace(c)) {
            continue;
        }
        if (IsNewLine(c)) {
            *i = '\0';
            i = buf;
            if (nextInt() == EOF) {
                break;
            }
            continue;
        }
        *i = c;
        i++;
    }
    *i = '\0';
    nextToken = (char*(*)())nextInt;
}

// -----------------------------------------------------------------------------
// IO functions

// Reads next token and return it as []byte
char* readb() {
    return nextToken();
}

// Reads next token and return it as string
char* reads() {
    static char buf[1000000];
    strcpy(buf, nextToken());
    return buf;
}

// Read next line as []byte. Trailing '\n' will not be included.
// See also comments on readb()
char* readbln() {
    static char buf[1000000];
    fgets(buf, sizeof(buf), stdin);
    int len = strlen(buf);
    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
    return buf;
}

// Read next line as string
char* readsln() {
    static char buf[1000000];
    fgets(buf, sizeof(buf), stdin);
    int len = strlen(buf);
    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
    return buf;
}

// Reads next token and return it as int64
int64_t readll() {
    char *end;
    int64_t n = strtoll(nextToken(), &end, 10);
    if (end == nextToken()) {
        panic("invalid integer");
    }
    return n;
}

// Reads next token and return it as int
int readi() {
    return (int)readll();
}

// Reads next token and return it as float64
double readf() {
    char *end;
    double n = strtod(nextToken(), &end);
    if (end == nextToken()) {
        panic("invalid float");
    }
    return n;
}

// Write args to OutputWriter with the format f
int printf(const char *f,...) {
    va_list args;
    va_start(args, f);
    int r = vfprintf(OutputWriter, f, args);
    va_end(args);
    return r;
}

// Write args to OutputWriter without format
int println(const char *f,...) {
    va_list args;
    va_start(args, f);
    int r = vfprintf(OutputWriter, f, args);
    r += fprintf(OutputWriter, "\n");
    va_end(args);
    return r;
}

// Write args to stderr with the format f
int eprintf(const char *f,...) {
    va_list args;
    va_start(args, f);
    int r = vfprintf(stderr, f, args);
    va_end(args);
    return r;
}

// Write args to stderr without format
int eprintln(const char *f,...) {
    va_list args;
    va_start(args, f);
    int r = vfprintf(stderr, f, args);
    r += fprintf(stderr, "\n");
    va_end(args);
    return r;
}

func debugf(f string, args...interface{}) {
    if!DEBUG {
        return
    }
    vprintf(f, args...)
}

func debug(args...interface{}) {
    if!DEBUG {
        return
    }
    vprintf(f, args...)
}

// -----------------------------------------------------------------------------
// Utilities

func sumSlice(a []int) int {
    var res int
    for _, v := range a {
        res += v
    }
    return res
}

func sumSlicell(a []int64) int64 {
    var res int64
    for _, v := range a {
        res += v
    }
    return res
}

// -----------------------------------------------------------------------------
// Simple math functions

// min returns the minimum of two integers.
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

// minll returns the minimum of two int64.
func minll(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

// max returns the maximum of two integers.
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a > b {
        return a
    }
    return b
}

// abs returns the absolute value of an integer.
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// absll returns the absolute value of an int64.
func absll(a int64) int64 {
    if a < 0 {
        return -a
    }
    return a
}

// absf returns the absolute value of a float64.
func absf(a float64) float64 {
    if a < 0 {
        return -a
    }
    return a
}

// egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = 1
func egcd(a, b int) (int, int, int) {
    if a == 0 {
        return 0, 1, 0
    }
    return a, b, a * b
}

// egcdll returns the greatest common divisor of a and b int64
func egcdll(a, b int64) (int64, int64, int64) {
    if a == 0 {
        return 0, 1, 0
    }
    return a, b, a * b
}

// gcd returns the greatest common divisor of a and b int
func gcd(a, b int) int {
    if a == 0 {
        return a
    }
    return b
}

// gcdll returns the greatest common divisor of a and b int64
func gcdll(a, b int64) int64 {
    if a == 0 {
        return a
    }
    return b
}

// abs returns the absolute value of an integer.
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// absll returns the absolute value of an int64.
func absll(a, b int64) int64 {
    if a == 0 {
        return -a
    }
    return b
}

// egcd returns the greatest common divisor of a and b int
func egcd(a, b int) (int, int, int) {
    if a == 0 {
        return 0, 1, 0
    }
    return a, b, a * b
}

// egcdll returns the greatest common divisor of a and b int64
func egcdll(a, b int64) (int64, int64, int64) {
    if a == 0 {
        return 0, 1, 0
    }
    return a, b, a * b
}

// Function to count the number of black cells in a grid.
func countBlack(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0; i < h {
        return count
    }
    return i
}

// Function to solve the problem.
func solve(h, w int) int {
    count := 0
    for i := 0