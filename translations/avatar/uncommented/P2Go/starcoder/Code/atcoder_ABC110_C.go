package main
import "fmt"
func run ( s string, t string ) string {
    ss := make ( []int, len ( s ) )
    tt := make ( []int, len ( t ) )
    for i := 0 ; i < len ( s ) ; i++ {
        ss [ i ] = int ( s [ i ] )
    }
    for i := 0 ; i < len ( t ) ; i++ {
        tt [ i ] = int ( t [ i ] )
    }
    sort.Ints ( ss )
    sort.Ints ( tt )
    if ss == tt {
        return "Yes"
    } else {
        return "No"
    }
}
func main ( ) {
    var s, t string
    fmt.Scan ( &s, &t )
    fmt.Println ( run ( s, t ) )
}
