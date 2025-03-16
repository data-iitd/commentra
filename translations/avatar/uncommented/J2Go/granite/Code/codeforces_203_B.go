
package main

import (
"bufio"
"fmt"
"os"
)

func main() {
in := bufio.NewReader(os.Stdin)
var N, M int
fmt.Fscanf(in, "%d %d\n", &N, &M)
black := make([][]int, N+2)
for i := range black {
black[i] = make([]int, N+2)
}
for m := 1; m <= M; m++ {
var x, y int
fmt.Fscanf(in, "%d %d\n", &x, &y)
for xx := x - 1; xx <= x+1; xx++ {
for yy := y - 1; yy <= y+1; yy++ {
if black[xx][yy]++; black[xx][yy] == 9 {
fmt.Println(m)
return
}
}
}
}
fmt.Println(-1)
}

