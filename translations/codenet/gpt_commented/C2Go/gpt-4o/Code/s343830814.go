package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Declare a buffer to hold the input string
    var buf [512]byte

    // Read a line of input from standard input (stdin) into the buffer
    reader := bufio.NewReader(os.Stdin)
    n, _ := reader.Read(buf[:])

    // Calculate the length of the input string
    len := n

    // Print the first character, the length of the string minus 3, and the second to last character
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])

    // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
