package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var N int
var n []int
var a int
var pos int
fmt.Scanf("%d", &N)
n = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &n[i])
}
a = 1
pos = 0
for i := 1; i < N; i++ {
if n[pos] > n[i] {
a += 1
pos = i
}
}
fmt.Printf("%d", a)
}
