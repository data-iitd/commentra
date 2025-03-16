#######
// Importing necessary Go libraries
#######
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

#######
// Main method is the entry point of the Go application
#######
func main() {

    // Creating a bufio.Scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Reading the first line of input as an array of strings
    str := strings.Split(scanner.Text(), " ")

    // Creating a bufio.Scanner object to read the second line of input as separate tokens
    scanner = bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)

    // Reading the first two integers as input
    a, _ := strconv.Atoi(scanner.Text())
    b, _ := strconv.Atoi(scanner.Text())

    // Reading the third line of input as a string
    scanner = bufio.NewScanner(os.Stdin)
    u := scanner.Text()

    // Checking if the first string from the first line matches with the given string 'u'
    if u == str[0] {

        // If the condition is true, then print the result as (a-1) and b
        fmt.Println((a - 1), b)

    } else {

        // If the condition is false, then print the result as a and (b-1)
        fmt.Println(a, (b - 1))
    }
}

