package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Define a pair type to hold an integer and a string
type P struct {
    first  int
    second string
}

// Array to hold pairs of scores and names
var v [22]P

// Vector to hold lists of indices for each number
var d [33][]int

func main() {
    var n int
    var m int
    var a int
    var i int
    var j int
    var k int
    var s string
    var t string
    var x int
    var y int
    var z int

    // Read the number of participants until a zero is encountered
    fmt.Scanf("%d", &n)
    for n!= 0 {
        // Clear the previous data in the vector of lists
        for i = 0; i < 33; i++ {
            d[i] = make([]int, 0)
        }

        // Loop through each participant
        for i = 0; i < n; i++ {
            v[i].first = 0
            fmt.Scanf("%s %d", &v[i].second, &m)

            // Loop through each score for the current participant
            for j = 0; j < m; j++ {
                fmt.Scanf("%d", &a)

                // Update the score of the current participant
                v[i].first += n - len(d[a])

                // Decrease the score of participants who have already received this score
                for k = 0; k < len(d[a]); k++ {
                    v[d[a][k]].first--
                }

                // Add the current participant's index to the list for this score
                d[a] = append(d[a], i)
            }
        }

        // Sort the participants based on their scores
        sort.Slice(v[:n], func(i, j int) bool {
            return v[i].first > v[j].first
        })

        // Output the participant with the highest score
        fmt.Printf("%d %s\n", v[0].first, v[0].second)

        // Read the number of participants until a zero is encountered
        fmt.Scanf("%d", &n)
    }
}

