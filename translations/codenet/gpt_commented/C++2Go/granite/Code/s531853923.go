
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare four integer variables to hold input values
    var a, b, c, d int

    // Create a scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read four integer values from user input
    for i := 0; i < 4; i++ {
        scanner.Scan()
        value, _ := strconv.Atoi(scanner.Text())
        switch i {
        case 0:
            a = value
        case 1:
            b = value
        case 2:
            c = value
        case 3:
            d = value
        }
    }

    // Check if the product of a and b is odd and the sum of c and d is odd
    if a*b%2 == 1 && (c+d)%2 == 1 {
        // If both conditions are true, output "No"
        fmt.Println("No")
    } else {
        // If either condition is false, output "Yes"
        fmt.Println("Yes")
    }
}
