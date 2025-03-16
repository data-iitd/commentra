
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    s := make([]int, 10) // Create an integer slice's' of length 10
    reader := bufio.NewReader(os.Stdin) // Create a buffer reader for reading input from the standard input
    for i := 0; i < 10; i++ { // Loop through the array's' and read 10 integers from the user
        input, _ := reader.ReadString('\n') // Read a line of input from the standard input and store it in the variable 'input'
        s[i], _ = strconv.Atoi(input) // Convert the input string to an integer and store it in the array's' at the current index
    }
    sort.Ints(s) // Sort the array's' in ascending order using the sort.Ints function from the sort package
    fmt.Println(s[4], s[5], s[6]) // Print the 4th, 5th and 6th smallest elements from the sorted array's' to the standard output
}

