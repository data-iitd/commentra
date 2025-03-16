
package main
import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)
var l []int64
var limit int64 = 10000000000
func gen ( number int64, four int, seven int ) {
    if ( number > limit ) {
        return
    }
    if ( number > 0 && four == seven ) {
        l = append ( l, number )
    }
    gen ( number * 10 + 4, four + 1, seven )
    gen ( number * 10 + 7, four, seven + 1 )
}
func main ( ) {
    gen ( 0, 0, 0 )
    sort.Ints ( l )
    reader := bufio.NewReader ( os.Stdin )
    n, _ := strconv.ParseInt ( Readln ( reader ), 10, 64 )
    ans := int64 ( 0 )
    for _, val := range l {
        if ( val >= n ) {
            ans = val
            break
        }
    }
    fmt.Println ( ans )
}
func Readln ( reader *bufio.Reader ) string {
    str, _ := reader.ReadString ( '\n' )
    return str
}
