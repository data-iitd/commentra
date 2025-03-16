

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Function to calculate the maximum sum of elements to the left of a given index
func maxLeft(n int) int {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    if n > 2 {
        return n - 2
    }
    return 0
}

func main() {
    // Create a new Scanner object to read input from the console
    scan := bufio.NewScanner(os.Stdin)

    // Read the number of test cases from the input
    scan.Scan()
    t, _ := strconv.Atoi(scan.Text())

    // Iterate through each test case
    for i := 0; i < t; i++ {
        scan.Scan()
        n, _ := strconv.Atoi(scan.Text())

        // Print the maximum left sum
        fmt.Println(maxLeft(n))
    }
}

Translate the above Go code to Python and end with comment "