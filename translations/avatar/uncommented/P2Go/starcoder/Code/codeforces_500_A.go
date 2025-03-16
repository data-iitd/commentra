package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var n, t int
var s []int
var current_cell int
fmt.Sscanf(strings.Join(os.Stdin.ReadString( ), ""), "%d %d", &n, &t)
s = make([]int, n)
for i := 0; i < n; i++ {
s[i], _ = strconv.Atoi(strings.Split(os.Stdin.ReadString( ), "\n")[0])
}
current_cell = 0
for current_cell <= t {
current_cell += s[current_cell-1]
if current_cell == t {
fmt.Println("YES")
os.Exit(0)
}
}
fmt.Println("NO")
}
