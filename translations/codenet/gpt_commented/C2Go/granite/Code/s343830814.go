
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a buffer to hold the input string and an integer to store its length
    var buf strings.Builder
    var len int

    // Create a scanner to read a line of input from standard input (stdin) into the buffer
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    buf.WriteString(scanner.Text())

    // Calculate the length of the input string
    len = buf.Len()

    // Print the first character, the length of the string minus 3, and the second to last character
    fmt.Printf("%c%d%c\n", buf.String()[0], len-3, buf.String()[len-2])
}

