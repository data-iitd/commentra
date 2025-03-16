// Import the Go utility library for string manipulation and input/output
import (
    "fmt"
    "strings"
)

// Define a function named 'generateString' that returns a string of numbers from 1 to 1000
func generateString() string {
    var sb strings.Builder // Create a strings.Builder object

    // Use a for loop to append numbers from 1 to 1000 to the strings.Builder object
    for i := 1; i <= 1000; i++ {
        sb.WriteString(fmt.Sprintf("%d", i)) // Append the current number to the strings.Builder object
    }

    // Convert the strings.Builder object to a string and return it
    return sb.String()
}

// Define the main function that reads user input and prints the result
func main() {
    // Read an integer value from the user input
    var n int
    fmt.Scan(&n)

    // Print the character at the specified index of the generated string
    fmt.Println(generateString()[n-1])
}

