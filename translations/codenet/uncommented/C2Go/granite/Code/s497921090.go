
package main

import "fmt"

func main() {
    var n, a, b uint64
    fmt.Scan(&n)
    b = (n * (n - 1)) / 2
    fmt.Println(b)
}

// END-OF-CODE

The above Go code is a translation of the given C code. It reads an unsigned 64-bit integer from the input, calculates the sum of all numbers from 1 to n-1, and then prints the result. The Go code uses the fmt package to read input and print output.