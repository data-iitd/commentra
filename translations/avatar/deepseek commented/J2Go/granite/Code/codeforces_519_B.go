

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a Scanner object to read input from the standard input stream
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of elements
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())

    // Initialize sums of subsets
    a, b, c := 0, 0, 0

    // Sum all n elements
    for i := 0; i < n; i++ {
        scanner.Scan()
        num, _ := strconv.Atoi(scanner.Text())
        a += num
    }

    // Sum n-1 elements
    for i := 0; i < n-1; i++ {
        scanner.Scan()
        num, _ := strconv.Atoi(scanner.Text())
        b += num
    }

    // Sum n-2 elements
    for i := 0; i < n-2; i++ {
        scanner.Scan()
        num, _ := strconv.Atoi(scanner.Text())
        c += num
    }

    // Calculate the differences
    x := a - b
    y := b - c

    // Output the results
    fmt.Println(x)
    fmt.Println(y)
}

