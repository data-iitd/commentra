package main
import "fmt"

func main() {
    var N, X int
    fmt.Scanf("%d %d", &N, &X)
    A := make([]int, N)
    for i := range A {
        fmt.Scanf("%d", &A[i])
    }
    S := make([]int, N)
    for i := 0; i < N; i++ {
        if i == 0 {
            S[i] = A[i]
        } else {
            S[i] = S[i-1] + A[i]
        }
    }
    ans := int(1e9)
    for k := 1; k <= N/2; k++ {
        E := k*X + 2*sum(S[j] for j := N-2*k-1; j >= 0; j -= k)
        ans = min(ans, E)
    }
    fmt.Println(ans + N*X + 5*S[N-1])
}

