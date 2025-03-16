package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare integer variables for input coefficients
    var a, b, c, d, e, f int
    // Declare double variables for the results of the equations
    var x, y float64

    // Continuously read input until EOF (End of File) is reached
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        // Split the input into individual tokens
        tokens := strings.Split(scanner.Text(), " ")
        // Convert the tokens into integers
        a, _ = strconv.Atoi(tokens[0])
        b, _ = strconv.Atoi(tokens[1])
        c, _ = strconv.Atoi(tokens[2])
        d, _ = strconv.Atoi(tokens[3])
        e, _ = strconv.Atoi(tokens[4])
        f, _ = strconv.Atoi(tokens[5])

        // Calculate the value of y using the given formula
        y = float64(c*d - f*a) / float64(b*d - e*a)
        // Calculate the value of x using the given formula
        x = float64(c*e - f*b) / float64(a*e - d*b)

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
}

