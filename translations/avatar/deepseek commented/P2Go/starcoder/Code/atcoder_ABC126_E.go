package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var (
N, M int
)
var (
edge [100001][]int
used [100001]bool
ans int
queue []int
)
reader := bufio.NewReader(os.Stdin)
fmt.Fscan(reader, &N, &M)
for i := 0; i < M; i++ {
var (
X, Y, Z int
)
fmt.Fscan(reader, &X, &Y, &Z)
edge[X] = append(edge[X], Y)
edge[Y] = append(edge[Y], X)
}
for i := 0; i < N; i++ {
used[i] = false
}
for i := 0; i < N; i++ {
if!used[i] {
ans++
queue = []int{i}
for len(queue) > 0 {
node := queue[0]
queue = queue[1:]
used[node] = true
for _, nextnode := range edge[node] {
if!used[nextnode] {
queue = append(queue, nextnode)
}
}
}
}
}
fmt.Println(ans)
}
