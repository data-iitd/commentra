// Importing necessary Go libraries for this program
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function is the entry point of the Go application
func main() {
    // Creating a new Scanner object to read user input from the standard input
    scan := bufio.NewScanner(os.Stdin)

    // Reading an integer value from the user input
    scan.Scan()
    x, _ := strconv.Atoi(scan.Text())

    // Determining a boolean value based on the condition x equals to 1
    bool := x == 1

    // Calculating the result based on the boolean value
    result := 0
    if!bool {
        result = 1
    }

    // Writing the result to the standard output
    fmt.Println(result)
}

