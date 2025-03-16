
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N, M int
    var a []int
    var p int

    // Reading the input
    fmt.Scan(&N, &M)

    // Initializing the ArrayList with zeros
    a = make([]int, N)
    for i := 0; i < N; i++ {
        a[i] = 0
    }

    // Reading the queries and updating the ArrayList accordingly
    for i := 0; i < M; i++ {
        var k int
        fmt.Scan(&k)

        for j := 0; j < k; j++ {
            var s int
            fmt.Scan(&s)
            s--

            // Updating the value of the element at the given index
            a[s] |= (1 << i)
        }
    }

    // Reading the integers and computing their XOR
    for i := 0; i < M; i++ {
        var x int
        fmt.Scan(&x)
        p |= (x << i)
    }

    var ans int

    // Iterating through all possible combinations of the ArrayList elements
    for s := 0; s < (1 << N); s++ { // 1 << N represents 2^N
        var t int

        // Computing the XOR of the current combination with the ArrayList elements
        for i := 0; i < N; i++ {
            if (s >> i) & 1 == 1 { // Checking if the i-th bit of the current combination is set
                t ^= a[i] // Updating the XOR of the current combination
            }
        }

        // Checking if the XOR of the current combination and the ArrayList elements is equal to the given integers
        if p == t {
            ans++ // Incrementing the count of valid answers
        }
    }

    fmt.Println(ans) // Printing the count of valid answers
}

