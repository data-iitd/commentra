package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the length of the string from user input
    n, _ := strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString()))

    // Read the string from user input
    s := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString())

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

