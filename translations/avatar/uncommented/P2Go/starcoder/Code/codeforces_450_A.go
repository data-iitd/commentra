package main
import (
"fmt"
)
func main() {
var n, m int
var l []int
fmt.Scanf("%d %d", &n, &m)
l = make([]int, n)
for i := 0; i < n; i++ {
fmt.Scanf("%d", &l[i])
}
l2 := make([]int, n)
for i := 0; i < n; i++ {
l2[i] = l[i] / m
if l[i] % m!= 0 {
l2[i] += 1
}
}
mx := 0
for i := 0; i < n; i++ {
if l2[i] > mx {
mx = l2[i]
ind = i
}
}
fmt.Printf("%d", ind+1)
}
