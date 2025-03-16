
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Read N and X from input
    reader := bufio.NewReader(os.Stdin)
    input := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    N, _ := strconv.Atoi(input[0])
    X, _ := strconv.Atoi(input[1])

    // Define the calc function which processes a list x
    func calc(x []int) int {
        // Define a nested sub function within calc for further processing
        func sub(y []int, debug bool) []int {
            // Print the current state of y if debug mode is on
            if debug {
                fmt.Println("D", y)
            }
            // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
            for len(y) > 1 {
                y = []int{sorted(y[i:i+3])[1] for i := 0; i < len(y)-2}
                // Print the current state of y if debug mode is on
                if debug {
                    fmt.Println("D", y)
                }
            }
            // Return the final single element of y
            return y
        }
        // Process the input list x using sub function
        y := sub(x, false)
        // Check if the final element of y is 2
        if y[0] == 2 {
            // Call sub again with debug mode on and print the result
            sub(x, true)
            fmt.Println("=", x)
        }
        // Return the first element of the final y
        return y[0]
    }

    // Check if X is 1 or N * 2 - 1, print "No" if true
    if X == 1 || X == N*2-1 {
        fmt.Println("No")
    } else {
        // Print "Yes" if X is not 1 or N * 2 - 1
        fmt.Println("Yes")
        // Construct the list xs based on the value of X
        var xs []int
        if X == N*2-2 {
            xs = append(make([]int, N-1), append([]int{X + 2, X - 1, X, X + 1}, make([]int, N-3)...)...)
        } else {
            ys := append(make([]int, N-3), append([]int{X + 2, X - 1, X, X + 1}, make([]int, N-3)...)...)
            xs = append(ys[:N-3], ys[N-3:]...)
        }
        // Print each element of xs
        for _, x := range xs {
            fmt.Println(x)
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func sorted(arr []int) []int {
    sort.Ints(arr)
    return arr
}

