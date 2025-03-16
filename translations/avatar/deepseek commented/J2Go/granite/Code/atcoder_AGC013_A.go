
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(reader.ReadLine())
    A := make([]int, N)
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(reader.ReadLine())
    }
    count := 0
    for i := 0; i < N; i++ {
        if i == N-1 {
            count++
        } else if A[i] == A[i+1] {
        } else if A[i] < A[i+1] {
            for A[i] <= A[i+1] {
                i++
                if i == N-1 {
                    break
                }
            }
            count++
        } else {
            for A[i] >= A[i+1] {
                i++
                if i == N-1 {
                    break
                }
            }
            count++
        }
    }
    fmt.Println(count)
}

