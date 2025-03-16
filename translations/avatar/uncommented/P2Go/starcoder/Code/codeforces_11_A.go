package main
import (
"fmt"
)
func main() {
var n, d, m, q int
var x []int
fmt.Scanf("%d %d", &n, &d)
x = make([]int, n)
for i := 0; i < n; i++ {
fmt.Scanf("%d", &x[i])
}
for a := 0; a < n - 1; a++ {
if x[a] >= x[a+1] {
q = int((x[a] - x[a+1]) / d + 1)
m = m + q
x[a+1] = x[a+1] + q * d
}
}
fmt.Printf("%d", m)
}
