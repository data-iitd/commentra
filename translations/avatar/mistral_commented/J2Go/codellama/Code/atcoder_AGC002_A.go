// Import the fmt package for formatting output
import "fmt"

// Define the main function as the entry point of the program
func main() {
  // Create a new Scanner object to read input from the standard input stream
  scanner := bufio.NewScanner(os.Stdin)

  // Read the first integer input from the user
  var a int
  scanner.Scan()
  fmt.Sscan(scanner.Text(), &a)

  // Read the second integer input from the user
  var b int
  scanner.Scan()
  fmt.Sscan(scanner.Text(), &b)

  // Check if the first integer 'a' is positive
  if a > 0 {
    // If 'a' is positive, print the message "Positive" to the standard output stream
    fmt.Println("Positive")
  }

  // Else if the second integer 'b' is non-negative
  else if b >= 0 {
    // If 'b' is non-negative, print the message "Zero" to the standard output stream
    fmt.Println("Zero")
  }

  // Else if the difference between 'b' and 'a' is even
  else if (b - a + 1) % 2 == 0 {
    // If the difference is even, print the message "Positive" to the standard output stream
    fmt.Println("Positive")
  }

  // Else, print the message "Negative" to the standard output stream
  else {
    fmt.Println("Negative")
  }
}

