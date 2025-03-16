

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a Scanner object to read input from the console
    in := bufio.NewReader(os.Stdin)

    // Read four integers from the console
    x, _ := strconv.Atoi(read(in))
    y, _ := strconv.Atoi(read(in))
    a, _ := strconv.Atoi(read(in))
    b, _ := strconv.Atoi(read(in))

    // Initialize a counter variable
    count := 0

    // Find the number of pairs (i, j) that satisfy the condition i < j
    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            // If i is less than j, continue to the next iteration of the inner loop
            if i <= j {
                continue
            }

            // Increment the counter if the condition is satisfied
            count++
        }
    }

    // Print the result
    fmt.Println(count)

    // Print all pairs (i, j) that satisfy the condition i < j
    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            // If i is less than j, print the pair
            if i <= j {
                fmt.Println(i, j)
            }
        }
    }
}

func read(in *bufio.Reader) string {
    str, _ := in.ReadString('\n')
    return str
}

