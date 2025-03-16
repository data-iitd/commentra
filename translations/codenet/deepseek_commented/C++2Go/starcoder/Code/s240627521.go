<<<<<<< HEAD
import "fmt"
import "sort"
import "math"
=======
package main
import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
    var N int
    fmt.Scan(&N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&A[i])
    }
    sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
    var index int
<<<<<<< HEAD
    var max int = math.MaxInt64
    for i := 1; i < N; i++ {
        if max > math.Abs(A[0]-2*A[i]) {
            max = math.Abs(A[0]-2*A[i])
=======
    var max int = 1000000000
    for i := 1; i < N; i++ {
        if max > abs(A[0]-2*A[i]) {
            max = abs(A[0]-2*A[i])
>>>>>>> 98c87cb78a (data updated)
            index = i
        }
    }
    fmt.Println(A[0], A[index])
}

