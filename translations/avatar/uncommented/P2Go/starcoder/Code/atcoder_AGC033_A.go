package main
import (
"fmt"
"math"
"os"
"strconv"
"strings"
)
func main() {
var h, w int
fmt.Sscanf(os.Args[1], "%d", &h)
fmt.Sscanf(os.Args[2], "%d", &w)
graph := make([][]int, h)
for i := 0; i < h; i++ {
graph[i] = make([]int, w)
for j := 0; j < w; j++ {
graph[i][j] = math.MaxInt32
}
}
for i := 0; i < h; i++ {
s := strings.Split(os.Args[i+3], "")
for j := 0; j < w; j++ {
if s[j] == "#" {
graph[i][j] = 0
}
}
}
for i := 0; i < h; i++ {
for j := 0; j < w; j++ {
if graph[i][j] == 0 {
continue
}
if j+1 < w && graph[i][j+1] > graph[i][j]+1 {
graph[i][j+1] = graph[i][j]+1
}
if j-1 >= 0 && graph[i][j-1] > graph[i][j]+1 {
graph[i][j-1] = graph[i][j]+1
}
if i+1 < h && graph[i+1][j] > graph[i][j]+1 {
graph[i+1][j] = graph[i][j]+1
}
if i-1 >= 0 && graph[i-1][j] > graph[i][j]+1 {
graph[i-1][j] = graph[i][j]+1
}
}
}
fmt.Println(graph)
fmt.Println(int(math.Max(float64(graph[0][0]), float64(graph[h-1][w-1]))))
}
