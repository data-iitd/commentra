package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Declare a buffer to read input
    reader := bufio.NewReader(os.Stdin)

    // Read a line from standard input
    buf, _ := reader.ReadString('\n')

    // Calculate the length of the string read
    len := len(buf)

    // Print the first character, its length (minus 3), and the last character
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

// <END-OF-CODE>
