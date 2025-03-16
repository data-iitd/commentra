package main
import (
"fmt"
"math"
"sort"
"strconv"
"strings"
)
func main() {
var n, m, x int
fmt.Scanf("%d %d %d", &n, &m, &x)
c := make([][]int, n)
for i := 0; i < n; i++ {
c[i] = make([]int, m)
for j := 0; j < m; j++ {
fmt.Scanf("%d", &c[i][j])
}
}
pre := make([]int, n)
for i := 0; i < n; i++ {
pre[i] = i
}
l := make([][]int, 0)
rem := make([]int, 0)
ans := 0
for i := 1; i <= n; i++ {
for j := 0; j < int(math.Pow(2, float64(i))); j++ {
k := make([]int, 0)
for ii := 0; ii < i; ii++ {
if j & (1 << ii)!= 0 {
k = append(k, ii)
}
}
ca := 0
for ii := 0; ii < i; ii++ {
ca += c[k[ii]][ii]
}
if ca < x {
rem = append(rem, j)
} else {
}
}
if len(rem) > 0 {
for j := 0; j < len(rem); j++ {
l = append(l[:rem[j]], l[rem[j]+1:]...)
}
rem = make([]int, 0)
}
if len(l) == 0 {
fmt.Println(-1)
return
}
}
for i := 0; i < len(l); i++ {
ca := 0
for j := 0; j < len(l[i]); j++ {
ca += c[l[i][j]][0]
}
if ans == 0 {
ans = ca
} else {
ans = min(ans, ca)
}
}
fmt.Println(ans)
}
func min(a, b int) int {
if a < b {
return a
}
return b
}
