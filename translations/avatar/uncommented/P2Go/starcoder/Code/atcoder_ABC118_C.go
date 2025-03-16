package main
import (
"fmt"
"math/big"
)
func main() {
var N int
var A []int
fmt.Scanf("%d", &N)
A = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d", &A[i])
}
gcd := big.NewInt(0)
for i := 0; i < N; i++ {
gcd.GCD(gcd, big.NewInt(int64(A[i])))
}
fmt.Println(gcd)
}
