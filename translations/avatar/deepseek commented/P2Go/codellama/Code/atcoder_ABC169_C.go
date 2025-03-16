
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Set the recursion limit to avoid infinite recursion
    setrecursionlimit(1000000)

    // Debugging function to print debug information if TERM_PROGRAM is in environ
    dbg := func(something ...interface{}) {
        if "TERM_PROGRAM" == os.Getenv("TERM_PROGRAM") {
            fmt.Println(something...)
        }
    }

    // Function to read input from stdin without trailing whitespace
    input := func() string {
        return strings.TrimSpace(os.Stdin.ReadString('\n'))
    }

    // Helper function to read a list of integers
    LMIIS := func() []int {
        return []int{int(input())}
    }

    // Helper function to read a single integer
    II := func() int {
        return int(input())
    }

    // Constant for modulo operation
    P := 1000000007

    // Constant for infinity
    INF := 1000000000

    // Read two inputs, convert one to integer and the other to scaled integer
    sa, sb := input(), input()
    a, _ := strconv.Atoi(sa)
    b, _ := strconv.Atoi(sb)

    // Perform the calculation and print the result
    fmt.Println(a * b / 100)
}

