
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a new scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Continuously read input until the end of file is reached
    for scanner.Scan() {
        // Split the input line into individual fields
        fields := strings.Fields(scanner.Text())
        
        // Convert the input fields to integers
        a, _ := strconv.Atoi(fields[0])
        b, _ := strconv.Atoi(fields[1])
        c, _ := strconv.Atoi(fields[2])
        d, _ := strconv.Atoi(fields[3])
        e, _ := strconv.Atoi(fields[4])
        f, _ := strconv.Atoi(fields[5])
        
        // Calculate the value of y using the given formula
        y := float64(c*d - f*a) / float64(b*d - e*a)
        // Calculate the value of x using the given formula
        x := float64(c*e - f*b) / float64(a*e - d*b)
        
        // Adjust y to 0 if it is a small negative number close to zero
        if y <= 0 && y > -0.0005 {
            y = 0
        }
        // Adjust x to 0 if it is a small negative number close to zero
        if x <= 0 && x > -0.0005 {
            x = 0
        }
        
        // Print the results x and y formatted to three decimal places
        fmt.Printf("%.3f %.3f\n", x, y)
    }
    
    // Check for any errors during input reading
    if err := scanner.Err(); err!= nil {
        fmt.Fprintln(os.Stderr, "Error reading input:", err)
        os.Exit(1)
    }
}

