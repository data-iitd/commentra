// Importing necessary Go packages for reading input from the console and writing output to the console
import (
    "bufio"
    "fmt"
    "os"
)

// Main function is the entry point of the Go application
func main() {

    // Declaring input_array as a slice of strings
    var input_array []string

    // Declaring result as an integer
    var result int

    // Creating a new instance of bufio.Reader to read input from the console
    reader := bufio.NewReader(os.Stdin)

    // Loop to read input from the console
    for {

        // Declaring str as a string
        var str string

        // Reading input from the console
        str, err := reader.ReadString('\n')

        // Check if an error occured
        if err!= nil {
            fmt.Println(err)
            return
        }

        // Removing the trailing new line character
        str = str[:len(str)-1]

        // Appending the string to the input_array
        input_array = append(input_array, str)

        // Breaking the loop if a zero string is encountered
        if "0" == str {
            break
        }
    }

    // Loop to increment result for each non-zero string encountered
    for _, str := range input_array {
        result++

        // Breaking the loop if a zero string is encountered
        if "0" == str {
            break
        }
    }

    // Printing the result to the console
    fmt.Println(result)
}

