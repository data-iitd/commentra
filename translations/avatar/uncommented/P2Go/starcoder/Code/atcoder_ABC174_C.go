package main
import (
"fmt"
"os"
)
func main() {
var k int
var t int
k = int(os.Stdin.Read( ))
t = 0
for i := 1; i <= k; i++ {
t = (t % k) * 10 + 7
if t % k == 0 {
fmt.Println(i)
break
}
} else {
fmt.Println(-1)
}
}
