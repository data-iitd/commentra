package main
import (
"fmt"
"os"
"bufio"
"strconv"
)
func main() {
var n, k int
var bb []int
var aa []int
var m int
var a, j, j_ int
sc := bufio.NewScanner(os.Stdin)
n, _ = strconv.Atoi(sc.Text())
k, _ = strconv.Atoi(sc.Text())
bb = make([]int, n)
for i := 0; i < n; i++ {
bb[i], _ = strconv.Atoi(sc.Text())
}
aa = make([]int, n)
m = 0
for a = n - 1; a >= 0; a-- {
j = 0
for bb[a] > 0 {
if aa[j] >= a + k {
bb[a]--
}
j++
}
for j_ = m++; j_ > j; j_-- {
aa[j_] = aa[j_ - 1]
}
aa[j] = a
}
for i := 0; i < n; i++ {
fmt.Print(aa[i] + 1, " ")
}
fmt.Println()
}
