// Importing necessary Go packages for reading input from the console and writing output to the console
import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

// Main function is the entry point of the Go application
func main() {

    // Creating a new scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Reading input array from the console
    scanner.Scan()
    input_array := strings.Split(scanner.Text(), " ")

    // Initializing result variable to 0
    result := 0

    // Iterating through each string in the input array
    for _, str := range input_array {

        // Incrementing result variable for each non-zero string encountered
        result++

        // Breaking the loop if a zero string is encountered
        if str == "0" {
            break
        }
    }

    // Writing the result to the console
    fmt.Println(result)
}

