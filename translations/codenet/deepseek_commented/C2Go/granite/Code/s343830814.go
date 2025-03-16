
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Step 1: Open stdin as a reader
    reader := bufio.NewReader(os.Stdin)

    // Step 2: Read input from stdin
    buf, _ := reader.ReadString('\n')

    // Step 3: Calculate the length of the input
    len := len(buf)

    // Step 4: Print the first character, the length minus 3, and the second last character of the input
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])

    // Step 5: Return 0 to indicate successful execution
    os.Exit(0)
}

