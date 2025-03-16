package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a new Scanner object to read input from the standard input stream
    sc := bufio.NewScanner(os.Stdin)

    // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    sec, _ := strconv.Atoi(sc.Text()) // Read the number of seconds
    per_num, _ := strconv.Atoi(sc.Text()) // Read the number of periods
    max_sec, _ := strconv.Atoi(sc.Text()) // Read the total number of seconds

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    max_sec = int(float64(max_sec) + 0.5) // Read the total number of seconds and convert it to double

    // Initialize a counter variable ans_num to zero
    ans_num := 0

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for i := sec; i < max_sec; i += sec {
        ans_num += per_num
    }

    // Print the result ans_num to the standard output stream
    fmt.Println(ans_num)

    // Close the Scanner object to release the system resources
    sc.Close()
}

