package main
import (
"fmt"
"math"
)
func main() {
var N int
var A [5]int
fmt.Scanf("%d", &N)
for i := 0; i < 5; i++ {
fmt.Scanf("%d", &A[i])
}
fmt.Printf("%d", int(math.Ceil(float64(N)/float64(min(A)))))
}
