package main
import (
"fmt"
)
func main() {
var r, D, x int
fmt.Scanf("%d %d %d", &r, &D, &x)
for i := 2; i < 12; i++ {
fmt.Println(int((math.Pow(r, i-1))*(x+float64(D)/(1-r))-float64(D)/(1-r)))
}
}
