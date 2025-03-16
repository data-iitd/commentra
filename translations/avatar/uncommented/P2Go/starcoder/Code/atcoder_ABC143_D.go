package main
import "sort"
import "fmt"
func main() {
    var n int
    fmt.Scan( &n )
    l := make( []int, n )
    for i := range l {
        fmt.Scan( &l[i] )
    }
    sort.Ints( l )
    ans := 0
    for i := 0 ; i < n ; i++ {
        for j := i + 1 ; j < n ; j++ {
            a := l[i]
            b := l[j]
            right := sort.Search( n, func( x int ) bool { return x >= a + b } )
            left := sort.Search( n, func( x int ) bool { return x > max( a - b, b - a ) } )
            tmp := max( 0, right - left )
            if left <= i && i < right {
                tmp -= 1
            }
            if left <= j && j < right {
                tmp -= 1
            }
            ans += tmp
    }
    fmt.Println( ans / 3 )
}
