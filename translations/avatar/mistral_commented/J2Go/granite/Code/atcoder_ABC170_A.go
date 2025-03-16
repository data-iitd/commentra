
// Importing necessary Go packages for reading input from the console and writing output to the console
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function is the entry point of the Go application
func main() {

    // Creating BufferedReader object to read input from the console
    reader := bufio.NewReader( os.Stdin )

    // Creating PrintWriter object to write output to the console
    writer := bufio.NewWriter( os.Stdout )

    // Reading input array from the console
    input_array, _ := reader.ReadString('\n')
    input_array = strings.Split( input_array, " " )

    // Initializing result variable to 0
    result := 0

    // Iterating through each string in the input array
    for _, str := range input_array {

        // Incrementing result variable for each non-zero string encountered
        if str!= "0" {
            result++
        } else {
            // Breaking the loop if a zero string is encountered
            break
        }
    }

    // Writing the result to the console
    fmt.Fprintln( writer, result )

    // Flushing the PrintWriter object to write the output to the console
    writer.Flush()
}

