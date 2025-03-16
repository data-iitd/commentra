package main
import "fmt"
func main() {
    var N, K int
    var A []int
    fmt.Scanf("%d %d", &N, &K)
    A = make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &A[i])
    }
    var ll, rr int64
    ll = -1000000000000000000
    rr = 1000000000000000000
    for {
        x := (ll + rr) / 2
        tot := 0
        for i := 0; i < N; i++ {
            if A[i] < 0 {
                l := -1
                r := N
                for {
                    c := (l + r) / 2
                    if A[i] * A[c] < x {
                        r = c
                    } else {
                        l = c
                    }
                    if l + 1 == r {
                        break
                    }
                }
                tot += N - r
            } else {
                l := -1
                r := N
                for {
                    c := (l + r) / 2
                    if A[i] * A[c] < x {
                        l = c
                    } else {
                        r = c
                    }
                    if l + 1 == r {
                        break
                    }
                }
                tot += r
            }
            if A[i] * A[i] < x {
                tot -= 1
        }
        tot /= 2
        if tot < K {
            ll = x
        } else {
            rr = x
        }
        if ll + 1 == rr {
            break
        }
    }
    fmt.Println(ll)
}
