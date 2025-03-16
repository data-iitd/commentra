package main
import (
    "fmt"
    "math"
)
var debug bool
func log ( text string ) {
    if debug {
        fmt.Println ( text )
    }
}
func parse_input ( lines_as_string string ) ( string , ) {
    var lines []string
    if lines_as_string == "" {
        debug = false
        lines = append ( lines , fmt.Sprintf ( "%s" , input ( ) ) )
    } else {
        debug = true
        lines = [ e for e in lines_as_string.split ( "\n" ) ] [ 1 : - 1 ]
    }
    c := [ e for e in lines [ 0 ].split ( " " ) ] [ 0 ]
    return ( c , )
}
func solve ( c string ) string {
    a := "abcdefghijklmnopqrstuvwxyz"
    i := a.index ( c )
    return a [ i + 1 ]
}
func main ( ) {
    result := solve ( * parse_input ( ) )
    if isinstance ( result , list ) {
        for r in result {
            fmt.Printf ( "%s" , r )
        }
    } else {
        fmt.Printf ( "%s" , result )
    }
}
