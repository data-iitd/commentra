
#include <stdio.h>
#include <stdlib.h>

// A helper function to print output
void out(int x,...) {
    va_list args;
    va_start(args, x);
    vprintf(args);
    printf("\n");
    va_end(args);
}

// Initialize a scanner for reading input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from the standard input
char* getString() {
    int bufSize = 1000000;
    char* buf = malloc(sizeof(char) * bufSize);
    scanf("%s", buf);
    return buf;
}

// Main function
int main() {
    // Initialize the scanner for reading input
    setbuf(stdin, NULL);
    setvbuf(stdout, NULL, _IONBF, 0);

    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree of size 'n'
    int* fw = (int*)malloc(sizeof(int) * n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = getInt();
        fw[i] += a;
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = getInt(), x = getInt();
            fw[p] += x;
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = getInt(), r = getInt();
            // Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            int sum = 0;
            for (int j = l; j < r; j++) {
                sum += fw[j];
            }
            out(sum);
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
typedef struct {
    int n;
    int* data;
} BIT;

// FenwickTree :
BIT* FenwickTree(int n) {
    BIT* ret = (BIT*)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int*)malloc(sizeof(int) * n);
    return ret;
}

// Add :
void Add(BIT* b, int p, int x) {
    p++;
    for (int i = p; i <= b->n; i += i & -i) {
        b->data[i-1] += x;
    }
}

// Sum :
int Sum(BIT* b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

int sum(BIT* b, int r) {
    int s = 0;
    for (int i = r; i > 0; i -= i & -i) {
        s += b->data[i-1];
    }
    return s;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data[p-1] += x
        p += p & -p
    }
}

// Sum :
func (b *BIT) Sum(l, r int) int {
    return b.sum(r) - b.sum(l)
}

func (b *BIT) sum(r int) int {
    s := 0
    for r > 0 {
        s += b.data[r-1]
        r -= r & -r
    }
    return s
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
type BIT struct {
    n    int
    data []int
}

// FenwickTree :
func FenwickTree(n int) *BIT {
    var ret BIT
    ret.n = n
    ret.data = make([]int, n)
    return &ret
}

// Add :
func (b *BIT) Add(p, x int) {
    p++
    for p <= b.n {
        b.data