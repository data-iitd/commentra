package main
import (
"fmt"
)
func main() {
var n, m int
fmt.Scanf("%d %d", &n, &m)
i := 1
for m >= i {
m -= i
i = (i%n) + 1
}
fmt.Println(m)
}
