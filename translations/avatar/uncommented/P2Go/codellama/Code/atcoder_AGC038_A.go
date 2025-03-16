package main
import "fmt"
func solve ( H int , W int , A int , B int ) {
    answer := make ( [][]string , H )
    for i := 0 ; i < H ; i++ {
        answer [ i ] = make ( []string , W )
        for j := 0 ; j < W ; j++ {
            if i < B {
                if j < A {
                    answer [ i ] [ j ] = "0"
                } else {
                    answer [ i ] [ j ] = "1"
                }
            } else {
                if j < A {
                    answer [ i ] [ j ] = "1"
                } else {
                    answer [ i ] [ j ] = "0"
                }
            }
        }
    }
    for i := 0 ; i < H ; i++ {
        fmt.Println ( string ( answer [ i ] ) )
    }
}
func main ( ) {
    var H int
    var W int
    var A int
    var B int
    fmt.Scan ( & H )
    fmt.Scan ( & W )
    fmt.Scan ( & A )
    fmt.Scan ( & B )
    solve ( H , W , A , B )
}
