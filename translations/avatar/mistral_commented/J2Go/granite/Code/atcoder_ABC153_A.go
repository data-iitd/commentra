
// Importing necessary Go libraries for reading input from the console and handling errors
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Main function is the entry point of the Go application
func main() {

    // Creating a bufio.Scanner object to read input from the console
    in := bufio.NewScanner(os.Stdin)

    // Reading a single line of input from the console and storing it as a String array
    in.Scan()
    str := in.Text()

    // Splitting the String array into individual elements and parsing them as integers
    h, _ := strconv.Atoi(str[0:1])
    a, _ := strconv.Atoi(str[2:3])

    // Initializing a variable 'num' to keep track of the number of steps
    num := 0

    // Using a for loop to simulate the given condition
    for i := 1; h > 0; i++ {

        // Subtracting 'a' from 'h' in each iteration
        h = h - a

        // Incrementing the 'num' variable after each successful subtraction
        num++
    }

    // Printing the final result 'num' to the console
    fmt.Println(num)
}

