
package main

import "fmt"
import "bufio"
import "os"

func main() {
    // Creating a scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Reading two integer values from the user
    scanner.Scan()
    a, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    b, _ := strconv.Atoi(scanner.Text())
    
    // Checking if the first integer 'a' is positive
    if a > 0 {
        fmt.Println("Positive") // Output "Positive" if 'a' is greater than 0
    } 
    // Checking if the second integer 'b' is non-negative (zero or positive)
    else if b >= 0 {
        fmt.Println("Zero") // Output "Zero" if 'b' is greater than or equal to 0
    } 
    // Checking if the difference between 'b' and 'a' plus 1 is even
    else if (b - a + 1) % 2 == 0 {
        fmt.Println("Positive") // Output "Positive" if the result is even
    } 
    // If none of the above conditions are met, it means the result is negative
    else {
        fmt.Println("Negative") // Output "Negative" for all other cases
    }
}

