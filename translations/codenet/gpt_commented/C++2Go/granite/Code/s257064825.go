
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Optimize input/output operations
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    // Read the input string from the user
    str, _ := reader.ReadString('\n')

    // Initialize a variable to hold the sum of digits
    sum := 0

    // Iterate through each character in the string
    for _, x := range str {
        // Convert character to integer and add to sum
        sum += int(x - '0')
    }

    // Check if the sum of digits is divisible by 9
    if sum%9 == 0 {
        // If divisible, print "Yes"
        fmt.Fprintln(writer, "Yes")
    } else {
        // If not divisible, print "No"
        fmt.Fprintln(writer, "No")
    }
}

