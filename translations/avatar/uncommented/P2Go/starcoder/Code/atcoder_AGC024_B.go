package main
import "fmt"
func main() {
    var N int
    fmt.Scan( &N )
    P := make( []int, N )
    for i := 0; i < N; i++ {
        fmt.Scan( &P[i] )
    }
    editorial( N, P )
}
func editorial( N int, P []int ) {
    if N == 1 {
        fmt.Println( 0 )
        return
    }
    a := make( []int, N + 1 )
    for i, p := range P {
        a[p] = i
    }
    tmp := 1
    max_len := 1
    for i := 1; i < N; i++ {
        if a[i] < a[i+1] {
            tmp += 1
            max_len = max( max_len, tmp )
        } else {
            tmp = 1
    }
    ans := N - max_len
    fmt.Println( ans )
}
