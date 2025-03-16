
// Importing necessary libraries
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "math"
)

// Main function is the entry point of the Go application
func main() {
    // Creating a bufio.Scanner object to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Reading an integer input from the user
    scanner.Scan()
    x, _ := strconv.Atoi(scanner.Text())

    // Checking if the number is even and not equal to 2
    if x!= 2 && x%2 == 0 {
        x++ // Increment the number if it's even and not 2
    }

    // Starting an infinite loop
    for {
        i := 3 // Declaring an integer variable 'i'
        sqrtNum := math.Sqrt(float64(x)) // Calculating the square root of the number 'x'

        // Checking for prime numbers using trial division method
        for i <= int(sqrtNum) {
            if x%i == 0 { // Checking if the number 'x' is divisible by 'i'
                break // If it's divisible, then 'i' is a factor and the loop is broken
            }
            i += 2 // Incrementing 'i' by 2 to check the next odd number
        }

        // If 'i' is greater than the square root, then the number 'x' is prime
        if i > int(sqrtNum) {
            break // Exiting the loop
        }

        // If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
        x += 2 // Incrementing the number by 2 to check the next odd number
    }

    // Printing the prime number found
    fmt.Println(x) // Printing the prime number found
}

