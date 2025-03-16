
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
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(reader.ReadLineString())
    A := make([][]int, N)
    for i, s := range strings.Split(reader.ReadLineString(), " ") {
        A[i] = []int{i + 1, strconv.Atoi(s)}
    }
    sort.Slice(A, func(i, j int) bool {
        return A[i][1] < A[j][1]
    })
    for i := 0; i < N-1; i++ {
        fmt.Printf("%d ", A[i][0])
    }
    fmt.Printf("%d\n", A[N-1][0])
}
