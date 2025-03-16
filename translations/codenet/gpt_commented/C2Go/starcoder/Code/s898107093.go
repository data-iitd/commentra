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
    // Declare pointers for storing team names and initialize scores
    var t, h []*string
    taro, hanako := 0, 0

    // Read the number of rounds (n) from input
    n, _ := strconv.Atoi(readLine())

    // Allocate memory for team names for both players
    t = make([]*string, n)
    h = make([]*string, n)

    // Loop through each round to read team names and calculate scores
    for i := 0; i < n; i++ {
        // Allocate memory for each team name (up to 100 characters)
        t[i] = new(string)
        h[i] = new(string)

        // Read team names for both players
        fmt.Sscan(readLine(), t[i])
        fmt.Sscan(readLine(), h[i])

        // Compare team names and update scores based on the comparison
        if *t[i] < *h[i] {
            // If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3
        }
        if *t[i] > *h[i] {
            // If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3
        }
        if *t[i] == *h[i] {
            // If both team names are the same, both players get 1 point
            taro += 1
            hanako += 1
        }
    }

    // Output the final scores of Taro and Hanako
    fmt.Printf("%d %d\n", taro, hanako)
}

func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    str, _, _ := buf.ReadLine()
    return strings.TrimRight(string(str), "\r\n")
}

