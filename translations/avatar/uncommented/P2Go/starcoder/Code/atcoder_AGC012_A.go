package main
import (
"fmt"
"sort"
)
func main() {
var n int
fmt.Scanf("%d", &n)
var A []int
for i := 0; i < n; i++ {
var x int
fmt.Scanf("%d", &x)
A = append(A, x)
}
sort.Ints(A)
ans := 0
for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
ans += A[i]
}
fmt.Println(ans)
}
