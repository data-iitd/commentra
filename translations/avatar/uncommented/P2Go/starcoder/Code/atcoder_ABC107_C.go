package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var N, K int
var lst []int
var lst_p, lst_m []int
var p, m int
var x, y int
var lastx, lasty int
var ans int
var j int
var k int
var str string
var str_lst []string
str = os.Args[1]
str_lst = strings.Split(str, " ")
N, _ = strconv.Atoi(str_lst[0])
K, _ = strconv.Atoi(str_lst[1])
lst = make([]int, N)
for i := 0; i < N; i++ {
str = os.Args[2+i]
lst[i], _ = strconv.Atoi(str)
}
lst_p = make([]int, 0)
lst_m = make([]int, 0)
for i := 0; i < N; i++ {
if lst[i] == 0 {
K--
}
if lst[i] > 0 {
lst_p = append(lst_p, lst[i])
} else {
lst_m = append(lst_m, lst[i])
}
}
p = 0
m = 0
x = 0
y = len(lst_m) - 1
lastx = len(lst_p)
lasty = len(lst_m)
func check(k int) int {
ans := 1000000000
for j := 0; j <= k; j++ {
if j > lastx || k-j > lasty {
} else {
if j == 0 {
p = 0
} else {
p = lst_p[j-1]
}
if k-j == 0 {
m = 0
} else {
m = lst_m[lasty-(k-j)]
}
ans = min(ans, 2*p+abs(m), p+2*abs(m))
}
}
return ans
}
fmt.Println(check(K))
}
