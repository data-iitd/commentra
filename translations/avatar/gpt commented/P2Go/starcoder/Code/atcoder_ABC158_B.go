package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Use bufio for faster input
var reader = bufio.NewReader(os.Stdin)

// Function to read a single integer from input
func readInt() int {
    n, _ := strconv.Atoi(readLine())
    return n
}

// Function to read multiple integers from input and return them as a map
func readInts() []int {
    line := readLine()
    return strings.Split(line, " ")
}

// Function to read multiple integers from input and return them as a list
func readIntSlice() []int {
    line := readLine()
    return strings.Split(line, " ")
}

// Function to read a single line from input
func readLine() string {
    line, _ := reader.ReadString('\n')
    return strings.TrimSpace(line)
}

func main() {
    // Define the modulo constant
    const mod = 1e9 + 7

    // Read input values: N (total items), A (items of type A), B (items of type B)
    n, a, b := readInt(), readInt(), readInt()

    // Initialize the answer variable
    ans := 0

    // Calculate how many complete cycles of (A + B) fit into N
    rep := n / (a + b)

    // Add the total items of type A from the complete cycles to the answer
    ans += rep * a

    // Calculate the remaining items after complete cycles
    res := n - rep * (a + b)

    // Add the minimum of remaining items or A to the answer
    ans += min(res, a)

    // Print the final answer
    fmt.Println(ans)
}

// Function to return the minimum of two values
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

