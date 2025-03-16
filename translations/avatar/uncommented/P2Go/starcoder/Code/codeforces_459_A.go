package main
import (
"fmt"
"math"
)
func main() {
given := input("")
l1 := strings.Split(given, " ")
l1 := [int(x) for x in l1]
x1 := l1[0]
y1 := l1[1]
x2 := l1[2]
y2 := l1[3]
denominator := x2 - x1
numerator := y2 - y1
if denominator!= 0 {
quotient := numerator / denominator
}
if numerator == 0 {
d := int(math.Sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))
x4 := x1
x3 := x2
y3 := y2 + d
y4 := y1 + d
fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
} else if denominator == 0 {
y4 := y2
y3 := y1
d := int(math.Sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))
x4 := x1 + d
x3 := x2 + d
fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
} else if quotient == 1 {
x4 := x2
x3 := x1
y4 := y1
y3 := y2
fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
} else if quotient == -1 {
x4 := x1
x3 := x2
y4 := y2
y3 := y1
fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
} else {
fmt.Printf("-1\n")
}
}
