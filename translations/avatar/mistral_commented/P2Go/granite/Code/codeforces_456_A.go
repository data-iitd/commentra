

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of tuples: ")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    m := make([][]int, n)
    for i := 0; i < n; i++ {
        fmt.Print("Enter tuple ", i+1, ": ")
        input := reader.ReadLine()
        m[i] = make([]int, 2)
        for j, s := range strings.Split(string(input), " ") {
            m[i][j], _ = strconv.Atoi(s)
        }
    }
    // We create a 2D slice'm' of size 'n', where each element is a slice of size 2, representing a tuple.

    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if m[i][1] < m[j][1] {
                m[i], m[j] = m[j], m[i]
            }
            // We sort the 2D slice'm' in descending order based on the second element of each tuple.
        }
    }

    a := m[0]
    // We initialize a variable 'a' with the first tuple in the sorted 2D slice.

    for i := 1; i < n; i++ {
        if m[i][1] > a[1] {
            fmt.Println("Happy Alex")
            return
        }
        // For each tuple 'i', we check if its second element (m[i][1]) is greater than the second element of the current tuple 'a'.
        a = m[i]
    }
    fmt.Println("Poor Alex")
}

