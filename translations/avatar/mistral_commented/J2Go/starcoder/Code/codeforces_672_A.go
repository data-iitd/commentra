// Import the Go standard library for string manipulation and input/output
import "fmt"
import "os"
import "strconv"

// Define a function named 'generateString' that returns a string
// representing a string of numbers from 1 to 1000
func generateString() string {
    var sb string = "" // Create a string variable

    // Use a for loop to append numbers from 1 to 1000 to the string variable
    for i := 1; i <= 1000; i++ {
        sb += strconv.Itoa(i) // Append the current number to the string variable
    }

    // Return the string variable
    return sb
}

// Define the main function that reads user input and prints the result
func main() {
    var n int
    fmt.Scanf("%d", &n) // Read an integer value from the user input

    // Print the character at the specified index of the generated string
    fmt.Println(generateString()[n-1])
}

