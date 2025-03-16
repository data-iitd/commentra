package main
import (
"fmt"
)
func main() {
var v1, v2, t, d int
fmt.Scanf("%d %d\n%d %d", &v1, &v2, &t, &d)
a := 1
v := v1
distance := 0
for i := 0; i < t; i++ {
if v - v2 > (t-i-1)*d {
a *= -1
v = (t-i-1)*d + v2
}
distance += v
v += a*d
}
fmt.Println(distance)
}
