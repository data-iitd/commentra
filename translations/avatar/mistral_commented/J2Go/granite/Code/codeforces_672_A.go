
// Import the Go utility library for string manipulation and input/output
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Define a function named 'generateString' that returns a string representing a string of numbers from 1 to 1000
func generateString() string {
    sb := &strings.Builder{} // Create a StringBuilder object

    // Use a for loop to append numbers from 1 to 1000 to the StringBuilder object
    for i := 1; i <= 1000; i++ {
        sb.WriteString(strconv.Itoa(i)) // Append the current number to the StringBuilder object
    }

    // Convert the StringBuilder object to a string and return it
    return sb.String()
}

// Define the main function that reads user input and prints the result
func main() {
    sc := bufio.NewScanner(os.Stdin) // Create a Scanner object to read user input

    // Read an integer value from the user input
    sc.Scan()
    n, _ := strconv.Atoi(sc.Text())

    // Print the character at the specified index of the generated string
    fmt.Println(string(generateString()[n-1]))
}

