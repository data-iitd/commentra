package main
import (
"fmt"
)
func main() {
var a, b, t int
fmt.Scanf("%d %d %d", &a, &b, &t)
cookie := 0
time := a
for time <= t+0.5 {
cookie += b
time += a
}
fmt.Println(cookie)
}
