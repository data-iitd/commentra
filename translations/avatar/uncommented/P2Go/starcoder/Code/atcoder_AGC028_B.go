package main
import (
"fmt"
"math"
)
func main() {
var (
N int
M int = 1000000
A []int
)
fmt.Scanf("%d\n", &N)
A = make([]int, N)
for i := 0; i < N; i++ {
fmt.Scanf("%d ", &A[i])
}
var (
Nsq int = 1000
fact [Nsq][Nsq]int
)
fact[0][0] = 1
for n := 1; n < Nsq; n++ {
fact[n][0] = fact[n-1][0]*n % M
for i := 1; i < n; i++ {
fact[n][i] = fact[n][i-1]*(n-i+1) % M
}
fact[n][n] = fact[n][n-1]*n % M
}
var (
j [N]int
inv [N]int
)
for i := 0; i < N; i++ {
inv[i] = pow(i+1, M-2, M)
}
for i := 1; i < N; i++ {
inv[i] += inv[i-1]
inv[i] %= M
}
for i := 0; i < N; i++ {
j[i] = i
}
for i := 0; i < N; i++ {
j[i], j[N-1-i] = j[N-1-i], j[i]
}
var temp [N]int
for i := 0; i < N; i++ {
temp[i] = inv[j[i]] + inv[N-1-j[i]] - 1
}
var ans int
for i := 0; i < N; i++ {
ans += A[i]*temp[i] % M
ans %= M
}
ans *= fact[N][N-1]
ans %= M
fmt.Println(ans)
}
func pow(x, y, m int) int {
var ans int = 1
for y > 0 {
if y&1 > 0 {
ans *= x
ans %= m
}
x *= x
x %= m
y >>= 1
}
return ans
}
