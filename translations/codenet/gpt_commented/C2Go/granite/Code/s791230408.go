
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables for input values and control variables
    var a, b, c, i, j, k int
    var max int

    // Read the number of test cases
    reader := bufio.NewReader(os.Stdin)
    j, _ = strconv.Atoi(reader.ReadLine())

    // Loop through each test case
    for i = 0; i < j; i++ {
        // Read three integers a, b, and c
        a, _ = strconv.Atoi(reader.ReadLine())
        b, _ = strconv.Atoi(reader.ReadLine())
        c, _ = strconv.Atoi(reader.ReadLine())

        // Initialize max to the value of a
        max = a
        k = 0 // k will track which number is the largest

        // Determine the maximum value among a, b, and c
        if max <= b {
            max = b // Update max to b if b is greater
            k = 1 // Set k to indicate b is the largest
        }
        if max <= c {
            max = c // Update max to c if c is greater
            k = 2 // Set k to indicate c is the largest
        }

        // Square the maximum value and the other two values
        max = max * max
        a = a * a
        b = b * b
        c = c * c

        // Check if the squared values satisfy the Pythagorean theorem
        if k == 0 && max == b+c {
            fmt.Println("YES") // a is the largest, check if a^2 = b^2 + c^2
        } else if k == 1 && max == a+c {
            fmt.Println("YES") // b is the largest, check if b^2 = a^2 + c^2
        } else if k == 2 && max == a+b {
            fmt.Println("YES") // c is the largest, check if c^2 = a^2 + b^2
        } else {
            fmt.Println("NO") // The values do not satisfy the condition
        }
    }
}

