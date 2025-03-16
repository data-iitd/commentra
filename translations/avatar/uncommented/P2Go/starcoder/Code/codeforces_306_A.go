package main
import (
"fmt"
)
func main() {
var n, m int
fmt.Scanf("%d %d", &n, &m)
q := n / m
r := n % m
a := make([]int, m)
for i := 0; i < m; i++ {
a[i] = q
}
for i := 0; i < r; i++ {
a[i] += 1
}
for i := 0; i < m; i++ {
fmt.Printf("%d ", a[i])
}
}
