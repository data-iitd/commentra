
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new Scanner object to read input from the standard input stream
    sc := bufio.NewScanner(os.Stdin)

    // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    sc.Scan()
    sec, _ := strconv.Atoi(sc.Text())
    sc.Scan()
    per_num, _ := strconv.Atoi(sc.Text())
    sc.Scan()
    max_sec, _ := strconv.Atoi(sc.Text())

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    max_sec = (float64(max_sec) + 0.5)

    // Initialize a counter variable ans_num to zero
    ans_num := 0

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for i := float64(sec); i < max_sec; i += float64(sec) {
        ans_num += per_num
    }

    // Print the result ans_num to the standard output stream
    fmt.Println(ans_num)
}

