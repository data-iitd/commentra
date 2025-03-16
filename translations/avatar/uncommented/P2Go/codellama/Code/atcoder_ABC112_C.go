package main
import "fmt"
func solve ( n int , ls_xyh [][]int ) string {
    x0 := 0
    for i := 0; i < n; i++ {
        if ls_xyh [ i ] [ 2 ] > 0 {
            x0 = ls_xyh [ i ] [ 0 ]
            y0 := ls_xyh [ i ] [ 1 ]
            h0 := ls_xyh [ i ] [ 2 ]
            break
        }
    }
    cands := make ( [][]int , 0 )
    for i := 0; i < 101; i++ {
        for j := 0; j < 101; j++ {
            cands = append ( cands , []int { i , j , h0 + abs ( i - x0 ) + abs ( j - y0 ) } )
        }
    }
    for i := 0; i < n; i++ {
        x := ls_xyh [ i ] [ 0 ]
        y := ls_xyh [ i ] [ 1 ]
        h := ls_xyh [ i ] [ 2 ]
        cands = [ ( cx , cy , ch ) for ( cx , cy , ch ) in cands if max ( ch - abs ( cx - x ) - abs ( cy - y ) , 0 ) == h ]
    }
    ( xx , yy , hh ) := cands [ 0 ]
    return fmt.Sprintf ( "%d %d %d" , xx , yy , hh )
}
func readQuestion ( ) ( int , [][]int ) {
    var n int
    fmt.Scan ( & n )
    ls_xyh := make ( [][]int , n )
    for i := 0; i < n; i++ {
        var x , y , h int
        fmt.Scan ( & x , & y , & h )
        ls_xyh [ i ] = []int { x , y , h }
    }
    return n , ls_xyh
}
func main ( ) {
    fmt.Println ( solve ( readQuestion ( ) ) )
}
