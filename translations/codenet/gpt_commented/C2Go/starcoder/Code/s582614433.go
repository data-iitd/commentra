package main

import (
    "fmt"
    "sort"
    "bufio"
    "os"
    "strconv"
    "strings"
)

// Define long long type for convenience
type ll int64

// Define a large constant for infinity
const INF = 1<<62 - 1

// Define a large prime number for modulo operations
const MOD = 1000000007

// Structure to hold edge information
type E struct {
    p ll // Weight or value associated with the edge
    i ll // Index of the edge
    s string // Name or identifier of the edge
}

// Function to sort an array in ascending order
func sortup(a []ll) {
    sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

// Function to sort an array in descending order
func sortdown(a []ll) {
    sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
}

// Function to compute (a^n) % m using modular exponentiation
func pom(a, n, m ll) ll {
    x := ll(1) // Initialize result
    for a %= m; n; n >>= 1 { // Loop until n is zero
        if n & 1 == 1 {
            x = x * a % m
        }
        a = a * a % m
    }
    return x
}

// Function to compute modular inverse using Fermat's little theorem
func invp(a, p ll) ll {
    return pom(a, p-2, p)
}

// Function to read input from stdin
func readInput(reader *bufio.Reader) (n, m ll) {
    fmt.Fscanf(reader, "%d\n", &n)
    return
}

// Function to read input from stdin
func readEdges(reader *bufio.Reader, n, m ll) []E {
    data := make([]E, n)
    for i := ll(0); i < n; i++ {
        fmt.Fscanf(reader, "%s %d\n", &data[i].s, &data[i].p)
        data[i].i = i
    }
    return data
}

// Function to sort edges based on the defined sorting criteria
func sortEdges(data []E) {
    sort.Slice(data, func(i, j int) bool {
        if data[i].s < data[j].s {
            return true
        } else if data[i].s > data[j].s {
            return false
        } else {
            return data[i].p > data[j].p
        }
    })
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, n, m ll, data []E) {
    for i := ll(0); i < n; i++ {
        fmt.Fprintln(writer, data[i].i+1)
    }
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    n, m = readInput(reader)
    data := readEdges(reader, n, m)
    sortEdges(data)
    printOutput(writer, n, m, data)
    writer.Flush()
}

