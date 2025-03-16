package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var n int
var l []int
var high int
var tower int
var maximum int
fmt.Scanf("%d", &n)
l = make([]int, n)
for i := 0; i < n; i++ {
fmt.Scanf("%d", &l[i])
}
high = 1
tower = n
maximum = 1
sort.Ints(l)
for i := 1; i < n; i++ {
if l[i] == l[i-1] {
tower--
high++
} else {
if high > maximum {
maximum = high
}
high = 1
}
}
if high > maximum {
maximum = high
}
fmt.Printf("%d %d\n", maximum, tower)
}
