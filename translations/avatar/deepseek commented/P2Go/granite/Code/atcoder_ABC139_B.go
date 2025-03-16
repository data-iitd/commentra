

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    a, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    // Taking two integer inputs, `a` and `b`.
    hole := 1
    i := 0
    // Initializing `hole` to 1 and `i` to 0.
    check := true
    // Setting a boolean variable `check` to `True`.
    for check {
        // The `for` loop runs as long as `check` is `True`.
        if hole >= b {
            // Checking if `hole` is greater than or equal to `b`.
            check = false
            // If so, set `check` to `False` to exit the loop.
        } else {
            hole = a * (i + 1) - i
            // If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
            i++
            // Increment `i` by 1.
        }
    }
    fmt.Println(i)
    // Finally, print the value of `i` after the loop exits.
}
