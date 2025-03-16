package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare variables for input and a map to store string entries
    var n int
    var str, com string
    T := make(map[string]bool)

    // Read the number of commands from input
    fmt.Scanf("%d", &n)

    // Loop through each command
    for i := 0; i < n; i++ {
        // Read the command and the associated string
        fmt.Scanf("%s%s", &com, &str)

        // Check if the command is 'insert' (indicated by the first character being 'i')
        if com[0] == 'i' {
            // Insert the string into the map with a value of true
            T[str] = true
        } else {
            // If the command is not 'insert', check if the string exists in the map
            if T[str] {
                // If the string exists, print "yes"
                fmt.Println("yes")
            } else {
                // If the string does not exist, print "no"
                fmt.Println("no")
            }
        }
    }
}

