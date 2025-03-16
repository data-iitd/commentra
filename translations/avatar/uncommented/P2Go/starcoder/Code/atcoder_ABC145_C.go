package main
import (
"fmt"
"math"
"sort"
"strconv"
"strings"
)
func main() {
var (
N int
x, y []int
)
fmt.Scanf("%d", &N)
x = make([]int, N)
y = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &x[i])
fmt.Scanf("%d", &y[i])
}
var (
distances []float64
indices []int
)
for i := 0; i < N; i++ {
indices = make([]int, N)
for j := 0; j < N; j++ {
indices[j] = j
}
permutations := perm(indices)
for _, permutation := range permutations {
var totalDistance float64
for k := 0; k < N-1; k++ {
f, t := permutation[k], permutation[k+1]
distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
totalDistance += distance
}
distances = append(distances, totalDistance)
}
}
result := sum(distances) / float64(len(distances))
fmt.Printf("%.2f\n", result)
}
func perm(a []int) [][]int {
var (
result [][]int
used []bool
)
used = make([]bool, len(a))
var backtrack func(int)
backtrack = func(i int) {
if i == len(a) {
tmp := make([]int, len(a))
copy(tmp, a)
result = append(result, tmp)
return
}
for j := 0; j < len(a); j++ {
if!used[j] {
used[j] = true
a[i], a[j] = a[j], a[i]
backtrack(i + 1)
used[j] = false
a[i], a[j] = a[j], a[i]
}
}
}
backtrack(0)
return result
}
func sum(a []float64) float64 {
var result float64
for _, v := range a {
result += v
}
return result
}
