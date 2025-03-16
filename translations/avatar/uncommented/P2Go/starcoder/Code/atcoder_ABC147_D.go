package main
import (
"fmt"
"math"
"os"
"strconv"
"strings"
)
func main() {
var N int
var A []int
var result int
var b int
var bs int
fmt.Scanf("%d", &N)
A = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &A[i])
}
for b = 0; b < 60; b++ {
bs = 0
for i := 0; i < N; i++ {
bs += A[i] >> b & 1
}
result = (result + bs * (N-bs) * int(math.Pow(2, float64(b)))) % 1000000007
}
fmt.Printf("%d\n", result)
}
