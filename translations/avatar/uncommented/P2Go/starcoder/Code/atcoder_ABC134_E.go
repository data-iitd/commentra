package main
import "fmt"
func main() {
    var N int
    fmt.Scan( &N )
    ans := make( [] [] int )
    for _ := range [ 1 << 20 ] {
        var A int
        fmt.Scan( &A )
        idx := binary_search( A )
        if idx == len(ans) {
            ans = append( ans, [] int{ A } )
        } else {
            ans[ idx ] = append( ans[ idx ], A )
        }
    }
    fmt.Println( len(ans) )
}
func binary_search( key int ) int {
    bad, good := -1, len(ans)
    for good-bad > 1 {
        mid := (bad+good)/2
        if ans[mid][-1] < key {
            good = mid
        } else {
            bad = mid
        }
    }
    return good
}
