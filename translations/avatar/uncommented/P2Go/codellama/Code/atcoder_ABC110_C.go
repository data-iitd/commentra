package main
import "fmt"
import "sort"
import "container/list"
func run ( s , t string ) string {
    ss := make ( []int , 0 )
    tt := make ( []int , 0 )
    for _, v := range s {
        ss = append ( ss , int ( v ) )
    }
    for _, v := range t {
        tt = append ( tt , int ( v ) )
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
    var s , t string
    fmt.Scan ( &s , &t )
    fmt.Println ( run ( s , t ) )
}
