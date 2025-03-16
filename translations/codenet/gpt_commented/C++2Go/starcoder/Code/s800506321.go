package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold input values and intermediate results
    var n, k, x, y, z int

    // Read the total number of items (n) from user input
    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    // Read the number of groups (k) from user input
    k, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    // Calculate the number of items in each group (integer division)
    x = n / k

    // Calculate the remainder to check if there are leftover items
    y = n % k

    // Check if there are leftover items after dividing into groups
    if y!= 0 {
        // If there are leftovers, set z to 1 (indicating at least one group has one extra item)
        z = x + 1 - x
    } else {
        // If there are no leftovers, set z to 0 (indicating all groups are even)
        z = x - x
    }

    // Output the result (0 or 1) indicating if there are leftover items
    fmt.Printf("%d\n", z)
}

