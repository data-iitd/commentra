package main
import (
"fmt"
)
func main() {
var N, M int
fmt.Scanf("%d %d", &N, &M)
balls := make([][2]int, N)
for i := 0; i < N; i++ {
balls[i] = [2]int{1, 0}
}
balls[0] = [2]int{0, 1}
for i := 0; i < M; i++ {
var x, y int
fmt.Scanf("%d %d", &x, &y)
w_x, r_x := balls[x-1][0], balls[x-1][1]
w_y, r_y := balls[y-1][0], balls[y-1][1]
if w_x >= 1 && r_x >= 1 {
balls[x-1][0] -= 1
balls[y-1][1] += 1
} else if w_x == 0 {
balls[x-1][1] -= 1
balls[y-1][1] += 1
} else {
balls[x-1][0] -= 1
balls[y-1][0] += 1
}
}
ans := 0
for i := 0; i < N; i++ {
if balls[i][1] > 0 {
ans += 1
}
}
fmt.Println(ans)
}
