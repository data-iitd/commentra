
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function starts here
func main() {
    // Declare and initialize variables
    var N string
    var S int

    // Read the input number from the standard input
    fmt.Print("Enter a number: ")
    reader := bufio.NewReader(os.Stdin)
    N, _ = reader.ReadString('\n')

    // Calculate the sum of digits of the number
    for i := 0; i < len(N); i++ {
        // Increment the sum by the ASCII value of the current digit
        // (subtracting the ASCII value of '0' to get the actual digit value)
        S += int(N[i]) - int('0')
    }

    // Check if the number is divisible by the sum of its digits
<<<<<<< HEAD
    if int(N) % S == 0 { // Convert the string to an integer using stoi()
=======
    if stoi(N) % S == 0 { // Convert the string to an integer using stoi()
>>>>>>> 98c87cb78a (data updated)
        fmt.Println("Yes") // Output "Yes" if the number is divisible
    } else {
        fmt.Println("No") // Output "No" otherwise
    }
}

