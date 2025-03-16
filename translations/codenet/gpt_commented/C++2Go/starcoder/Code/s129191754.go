package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) (a []int) {
    var n int
    _, err := fmt.Fscanln(reader, &n)
    if err!= nil {
        fmt.Println(err)
        os.Exit(1)
    }
    a = make([]int, n)
    for i := 0; i < n; i++ {
        _, err := fmt.Fscan(reader, &a[i])
        if err!= nil {
            fmt.Println(err)
            os.Exit(1)
        }
    }
    return
}

// Function to print output to stdout
func printOutput(a []int) {
    for i := 0; i < len(a); i++ {
        fmt.Printf("%d ", a[i])
    }
    fmt.Println()
}

// Function to sort the input array
func sortArray(a []int) {
    sort.Ints(a)
}

// Function to check for duplicates in the sorted array
func checkDuplicates(a []int) bool {
    for i := 0; i < len(a) - 1; i++ {
        if a[i] == a[i + 1] {
            return false
        }
    }
    return true
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    a := readInput(reader)
    sortArray(a)
    if checkDuplicates(a) {
        printOutput(a)
    } else {
        fmt.Println("NO")
    }
}

