package main
import (
"fmt"
"math"
)
func main() {
var N int
var S string
fmt.Scanf("%d\n%s", &N, &S)
func calculate(n int, s string) {
arr := []rune(s)
rNum := strings.Count(s, "R")
gNum := strings.Count(s, "G")
bNum := strings.Count(s, "B")
sum := 0
for step := 1; step <= math.Ceil(float64(n)/2)+1; step++ {
for i := 0; i < n-2*step; i++ {
s := string(arr[i]) + string(arr[i+step]) + string(arr[i+step*2])
if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
sum++
}
}
}
fmt.Println(rNum*gNum*bNum - sum)
}
calculate(N, S)
}
