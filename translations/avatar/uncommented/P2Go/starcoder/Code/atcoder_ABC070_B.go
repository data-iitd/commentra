package main
import (
    "fmt"
    "sort"
    "strconv"
    "strings"
)
func main() {
    var A []int
    _, err := fmt.Scanf("%d %d %d %d", &A[0], &A[1], &A[2], &A[3])
    if err!= nil {
        fmt.Println(err)
    }
    if A[1] <= A[2] || A[3] <= A[0] {
        fmt.Println(0)
    } else {
        sort.Ints(A)
        fmt.Println(A[2] - A[1])
    }
}

