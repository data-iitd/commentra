
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    su := make([]byte, 1000)  // Create a byte slice to store the input, initialized with a length of 1000
    susum := 0                  // Initialize a variable to hold the sum of the digits
    j := 0                      // Initialize a counter variable for the loop

    // Infinite loop to continuously read input until a specific condition is met
    for {
        // Loop to read characters into the slice until a newline is encountered or the limit is reached
        for j = 0; j < 1000; j++ {
            su[j], _, _ = reader.ReadByte()  // Read a byte from standard input
            if su[j] == '\n' {  // Check if the byte is a newline character
                break  // Break the loop if a newline character is encountered
            }
            susum = susum + int(su[j]-'0')  // Convert the byte to an integer and add it to the sum
        }

        // Check if the first character is '0', which indicates the end of input
        if su[0] == '0' {  // Exit the loop if the first character is '0'
            break
        }

        fmt.Println(susum)  // Print the sum of the digits read
        susum = 0            // Reset the sum for the next input
    }
}

// 