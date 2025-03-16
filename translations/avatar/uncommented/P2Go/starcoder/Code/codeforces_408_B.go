package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)
func main() {
reader := bufio.NewReader(os.Stdin)
var t int
fmt.Fscanln(reader, &t)
for i := 0; i < t; i++ {
var bought_count, made_count int
fmt.Fscanln(reader, &bought_count)
bought_count_map := make(map[string]int)
for j := 0; j < bought_count; j++ {
var color string
fmt.Fscanln(reader, &color)
bought_count_map[color]++
}
fmt.Fscanln(reader, &made_count)
made_count_map := make(map[string]int)
for j := 0; j < made_count; j++ {
var color string
fmt.Fscanln(reader, &color)
made_count_map[color]++
}
res := 0
for color := range made_count_map {
if _, ok := bought_count_map[color];!ok {
fmt.Println(-1)
return
}
res += min(bought_count_map[color], made_count_map[color])
}
fmt.Println(res)
}
}
