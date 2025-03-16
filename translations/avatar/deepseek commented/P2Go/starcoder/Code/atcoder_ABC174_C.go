package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var k int
var t int
var i int
k = readInt()
t = 0
for i = 1; i <= k; i++ {
t = (t%k)*10 + 7
if t%k == 0 {
fmt.Println(i)
break
}
}
if i > k {
fmt.Println(-1)
}
}
func readInt() int {
var n int
fmt.Scan(&n)
return n
}
