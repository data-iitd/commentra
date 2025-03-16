package main
import (
"fmt"
)
func main() {
var N int
var V []int
var C []int
var list []int
var ans int
var X int
var Y int
fmt.Scanf("%d", &N)
V = make([]int, N)
C = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &V[i])
fmt.Scanf("%d", &C[i])
}
list = make([]int, 0)
ans = 0
X = 0
Y = 0
for i := 0; i < N; i++ {
if V[i]-C[i] > 0 {
X = V[i]
Y = C[i]
list = append(list, X-Y)
}
}
fmt.Printf("%d", sum(list))
}
func sum(list []int) int {
ans := 0
for _, v := range list {
ans += v
}
return ans
}
