package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var N int
var a []int
var total int
fmt.Scanf("%d", &N)
a = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &a[i])
}
total = 0
for _, v := range a {
total ^= v
}
fmt.Println(strings.Join(strings.Fields(fmt.Sprint(a)), " "))
}
