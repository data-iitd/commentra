
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    A, _ := strconv.Atoi(reader.ReadLine()[0:1])
    B, _ := strconv.Atoi(reader.ReadLine()[0:1])
    ans := 0
    out := 1 // Initialize out to 1

    for out < B { // Continue the loop as long as out is less than B
        out-- // Decrement out by 1
        out += A // Increment out by A
        ans++ // Increment ans by 1
    }
    fmt.Println(ans) // Print the value of ans to the standard output
}

