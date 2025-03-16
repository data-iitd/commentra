

package main

import (
    "bufio" // bufio package for reading input from the console
    "fmt" // fmt package for printing output to the console
    "os" // os package for handling input/output exceptions
)

func main() {
    // Create a bufio.Scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Read the input number from the console and store it in the 'n' variable
    var n int
    fmt.Print("Enter a number: ")
    scanner.Scan()
    n, _ = fmt.Sscanf(scanner.Text(), "%d")

    // Call the'solve' function to calculate and print the result
    solve(n)
}

//'solve' function to calculate and print the result
func solve(n int) {
    // Calculate the result and print it to the console
    result := (n / 3) * 2
    if n%3 == 0 {
        result += 0
    } else {
        result += 1
    }
    fmt.Println(result)
}

Translate the above Go code to C++ and end with comment "