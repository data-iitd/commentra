<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "sort"
    "strings"
)

// Define a long long integer type for convenience
type ll int64

// Define a macro for a simple loop
#define rep(i, l, r) for i := l; i < r; i++

// Define a macro for a loop with a step
#define repp(i, l, r, k) for i := l; i < r; i += k

// Define a large number to represent infinity
<<<<<<< HEAD
const INF = 1<<62 - 1<<31
=======
const INF = 1 << 62 - 1
>>>>>>> 98c87cb78a (data updated)

// Define a macro to get the maximum of two values
#define max(p, q) ((p) > (q)? (p) : (q))

// Define a macro to get the minimum of two values
#define min(p, q) ((p) < (q)? (p) : (q))

// Define a macro to check if a bit is set in a number
#define bit(n, m) (((n) >> (m)) & 1)

// Function to sort in ascending order
func upll(a, b *ll) int {
    if *a < *b {
        return -1
    } else if *a > *b {
        return 1
    }
    return 0
}

// Function to sort in descending order
func downll(a, b *ll) int {
    if *a < *b {
        return 1
    } else if *a > *b {
        return -1
    }
    return 0
}

// Function to sort an array of long long values in ascending order using qsort
func sortup(a []ll) {
    sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

// Function to sort an array of long long values in descending order using qsort
func sortdown(a []ll) {
    sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
}

// Function to perform modular exponentiation
func pom(a, n, m ll) ll {
    x := ll(1)
    a %= m
<<<<<<< HEAD
    for ; n > 0; n >>= 1 {
        if n&1 > 0 {
=======
    for ; n; n >>= 1 {
        if n&1 == 1 {
>>>>>>> 98c87cb78a (data updated)
            x = x * a % m
        }
        a = a * a % m
    }
    return x
}

// Define a modulo value
const MOD = 1000000007

// Function to compute the modular multiplicative inverse
#define invp(a, p) pom(a, p - 2, p)

// Define a structure to hold edge information
type E struct {
    p ll
    i int
    s string
}

// Function to sort edges based on the string and then by the long long value
func esort(a, b *E) int {
    cmp := strings.Compare(a.s, b.s)
    if cmp!= 0 {
        return cmp
    }
    if a.p < b.p {
        return 1
    }
    return -1
}

// Array to hold edge data
var data [100]E

// Variables to hold the number of edges
var n, m ll

// Main function
func main() {
    // Read the number of edges
    fmt.Scanf("%d", &n)

    // Read each edge's string and long long value, and store the index
    rep(i, 0, n) {
        fmt.Scanf(" %s%d", &data[i].s, &data[i].p)
        data[i].i = i
    }

    // Sort the edges using qsort and the custom esort function
    sort.Slice(data[:], func(i, j int) bool { return esort(&data[i], &data[j]) < 0 })

    // Print the indices of the edges in the sorted order
    rep(i, 0, n) {
        fmt.Printf("%d\n", data[i].i+1)
    }
}

