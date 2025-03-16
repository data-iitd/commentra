// Importing necessary Go packages for reading input and handling errors
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a new reader to read input from the console
    reader := bufio.NewReader(os.Stdin)

    // Reading a single line of input from the console
    input, _ := reader.ReadString('\n')

    // Splitting the input string into a slice of strings
    str := bufio.NewScanner(reader)
    str.Scan()
    parts := str.Text()

    // Parsing the first two elements of the string slice as integers 'h' and 'a'
    h, _ := strconv.Atoi(parts[0:1])
    a, _ := strconv.Atoi(parts[2:3])

    // Initializing a variable 'num' to keep track of the number of steps
    num := 0

    // Using a for loop to simulate the given condition
    for h > 0 {
        // Subtracting 'a' from 'h' in each iteration
        h -= a

        // Incrementing the 'num' variable after each successful subtraction
        num++
    }

    // Printing the final result 'num' to the console
    fmt.Println(num)
}

// <END-OF-CODE>
