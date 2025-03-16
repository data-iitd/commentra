package main
import "fmt"
func solve ( S string , T string , A int , B int , U string ) {
    if S == U {
        A -= 1
    }
    if T == U {
        B -= 1
    }
    fmt.Println ( A , B )
    return
}
func main ( ) {
    var S string
    var T string
    var A int
    var B int
    var U string
    fmt.Scan ( &S )
    fmt.Scan ( &T )
    fmt.Scan ( &A )
    fmt.Scan ( &B )
    fmt.Scan ( &U )
    solve ( S , T , A , B , U )
}
