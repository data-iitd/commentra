
// Importing necessary Go libraries for this program
import (
    "bufio" // For reading user input
    "fmt"    // For printing output
    "os"     // For interacting with the operating system
)

func main() {
    // Creating a new bufio.Scanner object to read user input from the standard input
    scan := bufio.NewScanner(os.Stdin)

    // Reading an integer value from the user input
    scan.Scan()
    x, _ := fmt.Sscanf(scan.Text(), "%d")

    // Determining a boolean value based on the condition x equals to 1
    bool := x == 1

    // Calculating the result based on the boolean value
    result :=!bool

    // Printing the result to the standard output
    fmt.Println(result)
}

