
// Importing necessary Go libraries
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function starts here
func main() {

    // Creating BufferedReader object to read input
    reader := bufio.NewReader(os.Stdin)

    // Creating variable x and reading an integer input
    x, _ := strconv.Atoi(read(reader))

    // Initializing count variable to 0
    count := 0

    // Initializing temporary variable tmp with the value of x
    tmp := x

    // Setting x to 0
    x = 0

    // Starting a for loop that runs until x is equal to 360
    for x!= 360 {

        // Adding the value of tmp to x
        x = x + tmp

        // If x is greater than 360, then subtract 360 from it
        if x > 360 {
            x = x - 360
        }

        // Incrementing the count variable
        count++
    }

    // Printing the value of count to the console using fmt.Println
    fmt.Println(count)
}

// Function to read a string input from the console
func read(reader *bufio.Reader) string {
    str, _ := reader.ReadString('\n')
    return strings.TrimSpace(str)
}

// End of code comment
// 