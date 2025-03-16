
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Take an input from the user and assign it to the variable 'n'
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    n, _ := reader.ReadString('\n')

    // Initialize a list 'a' with some strings representing numbers
    a := []string{ "10", "100", "1000", "10000", "100000" }

    // Convert each element of the input 'n' to an integer using the'map' function
    // and then sum up all the integers using the'sum' function and assign the result to the variable 'new'
    new := sum( list(map(int, n)) )

    // Check if the input 'n' is present in the list 'a'
    if n in a:
        // If the input 'n' is present in the list 'a', then print the number 10
        fmt.Println(10)
    else:
        // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
        fmt.Println(new)
}

func sum(list []int) int {
    var result int
    for _, num := range list {
        result += num
    }
    return result
}

// END-OF-CODE