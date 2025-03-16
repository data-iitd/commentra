package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read a string input from the user
    str, _ := os.Readline()

    // Check if the characters at positions 2 and 3 are the same,
    // and if the characters at positions 4 and 5 are the same
    if str[2] == str[3] && str[4] == str[5] {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

