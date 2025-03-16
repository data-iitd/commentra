
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var x int
    var ans int

    // Read an integer input from the user
    input, _ := reader.ReadString('\n')
    x, _ = strconv.Atoi(input)

    // Calculate the result as the sum of x, x squared, and x cubed
    ans = x + x*x + x*x*x

    // Output the calculated result to the console
    fmt.Println(ans)
}

