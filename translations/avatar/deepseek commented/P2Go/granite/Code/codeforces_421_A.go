

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

    var n, a, b int
    fmt.Fscanf(reader, "%d %d %d\n", &n, &a, &b)
    // The first line takes three integers n, a, and b as input, separated by spaces.
    lista := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &lista[i])
        // The second line takes a list of integers lista as input, separated by spaces.
    }
    listb := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &listb[i])
        // The third line takes a list of integers listb as input, separated by spaces.
    }
    for k := 0; k < n; k++ {
        // The for loop iterates over the range n.
        if contains(lista, k+1) {
            // If the current index k + 1 is in the list lista,
            fmt.Printf("1 ")
            // print 1 to the console.
        } else {
            // Otherwise,
            fmt.Printf("2 ")
            // print 2 to the console.
        }
    }
    fmt.Println()
}

func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

