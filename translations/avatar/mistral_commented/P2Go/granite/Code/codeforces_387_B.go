
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables n and m with the given input
    reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)
    mTemp, err := reader.ReadString('\n')
    checkError(err)
    m, err := strconv.ParseInt(strings.TrimSpace(mTemp), 10, 64)
    checkError(err)

    // Initialize lists round_complexity and george_complexity
    // with the given input
    round_complexity := make([]int64, n)
    for i := int64(0); i < n; i++ {
        round_complexityTemp, err := reader.ReadString(' ')
        checkError(err)
        round_complexity[i], err = strconv.ParseInt(strings.TrimSpace(round_complexityTemp), 10, 64)
        checkError(err)
    }
    george_complexity := make([]int64, m)
    for i := int64(0); i < m; i++ {
        george_complexityTemp, err := reader.ReadString('\n')
        checkError(err)
        george_complexity[i], err = strconv.ParseInt(strings.TrimSpace(george_complexityTemp), 10, 64)
        checkError(err)
    }

    // Initialize variables i and j to 0
    i, j := int64(0), int64(0)

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    for i < n && j < m {
        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        if round_complexity[i] <= george_complexity[j] {
            i++
        }
        // Increment j
        j++
    }

    // Print the final answer
    fmt.Println(n - i)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

