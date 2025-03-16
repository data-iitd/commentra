

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Read two integer values from the standard input using `fmt.Fscanf`
    var a, b int
    fmt.Fscanf(reader, "%d %d\n", &a, &b)

    // Calculate the difference between `6` and the sum of `a` and `b`
    result := 6 - a - b

    // Print the result to the standard output using `fmt.Println`
    fmt.Println(result)
}

