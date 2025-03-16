package main
import "fmt"
import "sort"
import "os"
func main() {
    a := sort.IntSlice ( make ( []int, 0, 1000000 ) )
    for _, v := range ( os.Args [ 1 : ] ) {
        a = append ( a, 0 )
        a [ len ( a ) - 1 ], _ = fmt.Sscanf ( v, "%d", & a [ len ( a ) - 1 ] )
    }
    sort.Sort ( a )
    fmt.Println ( a [ 0 ] )
    fmt.Println ( - 1 )
}
