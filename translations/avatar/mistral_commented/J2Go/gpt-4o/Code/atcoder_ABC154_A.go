package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Creating a BufferedReader object to read input from the console
    reader := bufio.NewReader(os.Stdin)

    // Reading the first line of input as a string
    firstLine, _ := reader.ReadString('\n')
    str := strings.Fields(firstLine)

    // Reading the second line of input as separate tokens
    secondLine, _ := reader.ReadString('\n')
    tokens := strings.Fields(secondLine)

    // Reading the first two integers as input
    a, _ := strconv.Atoi(tokens[0])
    b, _ := strconv.Atoi(tokens[1])

    // Reading the third line of input as a string
    thirdLine, _ := reader.ReadString('\n')
    u := strings.TrimSpace(thirdLine)

    // Checking if the first string from the first line matches with the given string 'u'
    if u == str[0] {
        // If the condition is true, then print the result as (a-1) and b
        fmt.Printf("%d %d\n", a-1, b)
    } else {
        // If the condition is false, then print the result as a and (b-1)
        fmt.Printf("%d %d\n", a, b-1)
    }
}

// <END-OF-CODE>
