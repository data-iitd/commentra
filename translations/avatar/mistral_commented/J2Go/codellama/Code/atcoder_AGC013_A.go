
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N int
    var A []int
    var count int

    // Reading the number of elements in the array from the standard input
    N, _ = strconv.Atoi(os.Args[1])

    // Creating an integer array of size N
    A = make([]int, N)

    // Reading the elements of the array from the standard input
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(os.Args[i+2])
    }

    // Iterating through the array to find the number of increasing and decreasing sequences
    for i := 0; i < N-1; i++ {
        if i == N-1 {
            count++
        } else if A[i] == A[i+1] {
        } else if A[i] < A[i+1] {
            for j := i + 1; j < N; j++ {
                if A[i] <= A[j] {
                    i = j
                    if i == N-1 {
                        break
                    }
                }
            }
            count++
        } else {
            for j := i + 1; j < N; j++ {
                if A[i] >= A[j] {
                    i = j
                    if i == N-1 {
                        break
                    }
                }
            }
            count++
        }
    }

    fmt.Println(count)
}

