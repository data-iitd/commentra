package main
import (
"fmt"
)
func main() {
var k, n, w int
fmt.Scanf("%d %d %d", &k, &n, &w)
total := 0
for i := 1; i <= w; i++ {
total += i * k
}
if total > n {
fmt.Println(total - n)
} else {
fmt.Println(0)
}
}
