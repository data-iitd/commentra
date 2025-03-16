
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new Scanner object to read input from the standard input stream
    sc := bufio.NewScanner(os.Stdin)

    // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    var sec int
    var per_num int
    var max_sec int

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    var max_sec float64

    // Initialize a counter variable ans_num to zero
    var ans_num int

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for i := sec; i < max_sec; i += sec {
        ans_num += per_num
    }

    // Print the result ans_num to the standard output stream
    fmt.Println(ans_num)

    // Close the Scanner object to release the system resources
    sc.Close()
}

