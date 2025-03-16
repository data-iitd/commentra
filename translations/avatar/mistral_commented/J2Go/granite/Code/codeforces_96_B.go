

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize scanner to read input from standard input
    in := bufio.NewReader(os.Stdin)

    // Read a long number as input
    number, _ := in.ReadString('\n')
    number = strings.TrimSpace(number)

    // Initialize variables for answer and current value
    ans := int64(-1)
    value := int64(0)

    // Initialize mask variable for binary number manipulation
    mask := 2

    // Main loop to find the answer
    for value < int64(number) {
        // Convert mask to binary string and remove leading '1'
        s := fmt.Sprintf("%b", mask)
        s = s[1:]

        // Count the number of zeros in the binary string
        zeros := 0
        for _, c := range s {
            if c == '0' {
                zeros++
            }
        }

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if zeros!= len(s)-zeros {
            mask++
            continue
        }

        // Replace all zeros with '4' and all ones with '7' in the binary string
        s = strings.ReplaceAll(s, "0", "4")
        s = strings.ReplaceAll(s, "1", "7")

        // Convert the modified binary string back to a long number and update the value variable
        value, _ = strconv.ParseInt(s, 10, 64)
    }

    // Print the answer
    fmt.Println(value)
}

