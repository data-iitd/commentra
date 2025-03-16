package main
import "fmt"
import "math"

func lcm(a, b int) int {
    return a * b / int(math.GCD(float64(a), float64(b)))
}

func main() {
    var N int
    fmt.Scanf("%d", &N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &A[i])
    }
    lcm := 1
    for _, a := range A {
        lcm = lcm * a / int(math.GCD(float64(lcm), float64(a)))
    }
    ans := lcm
    for _, a := range A {
        ans = ans * pow(a, MOD-2, MOD) % MOD
    }
    fmt.Println(ans)
}

func pow(a, b, m int) int {
    ans := 1
    for b > 0 {
        if b&1 == 1 {
            ans = ans * a % m
        }
        a = a * a % m
        b >>= 1
    }
    return ans
}

