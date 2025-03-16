

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the values of n and m from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the value of n: ")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    fmt.Print("Enter the value of m: ")
    m, _ := strconv.Atoi(reader.ReadLine()[0])

    // Initialize an array of size m
    a := make([]int, m)

    // Check if n is divisible by m
    if n%m == 0 {
        // Fill the array with equal parts if n is divisible by m
        for i := 0; i < len(a); i++ {
            a[i] = n / m
        }
    } else {
        // Calculate the base part size
        sub := n / m

        // Fill the array with the base part size
        for i := 0; i < len(a); i++ {
            a[i] = sub
        }

        // Distribute the remainder
        test := n - (sub * m)
        count := 0
        for i := 0; i < test; i++ {
            a[count] = a[count] + 1
            count++
            if count >= len(a) {
                count = 0
            }
        }
    }

    // Print the array elements in reverse order
    for i := len(a) - 1; i >= 0; i-- {
        fmt.Print(a[i], " ")
    }
    fmt.Println()
}

