
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an integer variable to store the length of the string
    var n int

    // Read the length of the string from user input
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        var err error
        n, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            fmt.Println("Invalid input for length of the string")
            return
        }
    } else {
        fmt.Println("Failed to read length of the string from input")
        return
    }

    // Declare a string variable to store the input string
    var s string

    // Read the string from user input
    if scanner.Scan() {
        s = scanner.Text()
    } else {
        fmt.Println("Failed to read string from input")
        return
    }

    // Initialize a counter to count the number of distinct segments
    cnt := 0

    // Iterate through each character in the string
    for i := 0; i < n; i++ {
        // Increment the counter for each new segment found
        cnt++

        // Initialize a variable j to find the end of the current segment
        j := i + 1

        // Continue moving j forward as long as the characters are the same
        for ; j < n; j++ {
            // If the current character is different from the next character, break the loop
            if s[i]!= s[j] {
                break
            }
        }

        // Move i to the end of the current segment
        i = j - 1
    }

    // Output the total count of distinct segments
    fmt.Println(cnt)
}

