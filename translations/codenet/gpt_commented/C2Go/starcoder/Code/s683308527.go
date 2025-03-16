package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    var n int
    var s string
    var c string

    // Read the number of lines to process, ignoring the newline character
    fmt.Scanf("%d\n", &n)

    // Loop to process each line of input
    for n > 0 {
        // Read a line of input from stdin
        s = bufio.NewReader(os.Stdin).ReadString('\n')

        // Search for the substring "Hoshino" in the input line
        // Replace the character following "Hoshino" with 'a'
        for c = strings.Index(s, "Hoshino"); c!= -1; c = strings.Index(s, "Hoshino") {
            s = s[:c+6] + "a" + s[c+7:]
        }

        // Print the modified line
        fmt.Println(s)

        n--
    }
}

