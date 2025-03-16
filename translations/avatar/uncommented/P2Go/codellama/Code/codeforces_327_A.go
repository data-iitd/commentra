package main
import "fmt"
func find ( s string , ch byte ) []int {
    var indices []int
    for i , ltr := range s {
        if ltr == ch {
            indices = append ( indices , i )
        }
    }
    return indices
}
func main() {
    var n int
    fmt.Scan ( &n )
    var s string
    fmt.Scan ( &s )
    if !strings.Contains ( s , "0" ) {
        fmt.Println ( n - 1 )
    } else {
        indices := find ( s , '0' )
        if len ( indices ) == 1 {
            fmt.Println ( n )
        } else {
            maximum := 0
            combs := combinations ( indices , 2 )
            for x := range combs {
                maximum = max ( maximum , 2 + 2 * ( abs ( indices.index ( x [ 0 ] ) - indices.index ( x [ 1 ] ) ) - 1 ) - ( abs ( x [ 0 ] - x [ 1 ] ) - 1 ) )
            }
            fmt.Println ( s.count ( '1' ) + maximum )
        }
    }
}



Translate the above Go code to C++ and end with comment "