
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Creating a bufio.Scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Reading a line of input from the user
    scanner.Scan()
    a := scanner.Text()
    
    // Replacing commas in the input string with spaces and printing the modified string
    fmt.Println(strings.Replace(a, ",", " ", -1))
}

