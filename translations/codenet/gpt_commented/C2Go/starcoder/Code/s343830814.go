package main

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a buffer to hold the input string and an integer to store its length
    var buf [512]byte
    var len int

    // Read a line of input from standard input (stdin) into the buffer
    fmt.Fscanln(os.Stdin, &buf)

    // Calculate the length of the input string
    len = len(buf)

    // Print the first character, the length of the string minus 3, and the second to last character
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

