package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to read a single integer from input
func next_int() int {
    sc := bufio.NewScanner(os.Stdin)
    sc.Scan()
    i, _ := strconv.Atoi(sc.Text())
    return i
}

// Function to read a list of integers from input
func next_ints() []int {
    sc := bufio.NewScanner(os.Stdin)
    sc.Scan()
    i, _ := strconv.Atoi(sc.Text())
    return strings.Split(sc.Text(), " ")
}

func main() {
    n := next_int()
    t := 0
    for i := 0; i < n; i++ {
        if (i + 1) & 1 == 1 {
            t += 1
        }
    }
    fmt.Printf("%.6f\n", float64(t)/float64(n))
}

