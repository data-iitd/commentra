<<<<<<< HEAD

import "fmt"
import "sort"
import "math"

func main() {
    var N int
    fmt.Scanf("%d", &N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &A[i])
    }
    sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
    var index int
    var max int = math.MaxInt64
    for i := 1; i < N; i++ {
        if max > math.Abs(A[0]-2*A[i]) {
            max = math.Abs(A[0]-2*A[i])
            index = i
        }
    }
    fmt.Printf("%d %d\n", A[0], A[index])
=======
_

package main
import (
"fmt"
"sort"
)
func main() {
var N int
fmt.Scanf("%d", &N)
A := make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &A[i])
}
sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
var index int
var max int = 1e9
for i := 1; i < N; i++ {
if max > abs(A[0]-2*A[i]) {
max = abs(A[0]-2*A[i])
index = i
}
}
fmt.Printf("%d %d\n", A[0], A[index])
>>>>>>> 98c87cb78a (data updated)
}

