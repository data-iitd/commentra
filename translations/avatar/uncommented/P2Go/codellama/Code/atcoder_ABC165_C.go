package main
import "fmt"
func solve ( N int , M int , Q int , a []int , b []int , c []int , d []int ) {
    res := 0
    var rec func ( A []int )
    rec = func ( A []int ) {
        if len ( A ) == N {
            ans := 0
            for i := 0; i < Q; i++ {
                if A [ b [ i ] - 1 ] - A [ a [ i ] - 1 ] == c [ i ] {
                    ans += d [ i ]
                }
            }
            res = max ( res , ans )
            return
        }
        last_max := 1 if len ( A ) == 0 else A [ len ( A ) - 1 ]
        for i := last_max; i <= M; i++ {
            rec ( append ( A , i ) )
        }
    }
    rec ( []int { } )
    fmt.Println ( res )
    return
}
func main ( ) {
    var iterate_tokens func ( )
    iterate_tokens = func ( ) {
        for line := range ( os.Stdin ) {
            for word := range ( strings.Split ( line , " " ) ) {
                yield word
            }
        }
    }
    tokens := iterate_tokens ( )
    N := int ( next ( tokens ) )
    M := int ( next ( tokens ) )
    Q := int ( next ( tokens ) )
    a := make ( []int , Q )
    b := make ( []int , Q )
    c := make ( []int , Q )
    d := make ( []int , Q )
    for i := 0; i < Q; i++ {
        a [ i ] = int ( next ( tokens ) )
        b [ i ] = int ( next ( tokens ) )
        c [ i ] = int ( next ( tokens ) )
        d [ i ] = int ( next ( tokens ) )
    }
    solve ( N , M , Q , a , b , c , d )
}
