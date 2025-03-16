package main
import (
"fmt"
"sort"
"strconv"
"strings"
)
func main() {
var n, k int
fmt.Sscanf(strings.Join(strings.Fields(fmt.Scanf("%d %d\n")), " "), "%d %d", &n, &k)
fmt.Println(sum(sort.IntSlice(make([]int, n)).Sort(func(i, j int) bool { return less(i, j) })))
}
func less(i, j int) bool {
return i < j
}
func sum(a []int) int {
var s int
for _, v := range a[:k] {
s += v
}
return s
}
