package main
import (
"fmt"
)
func main() {
var t, s, q int
fmt.Scanf("%d %d %d", &t, &s, &q)
ans := 0
for s < t {
s *= q
ans++
}
fmt.Println(ans)
}
