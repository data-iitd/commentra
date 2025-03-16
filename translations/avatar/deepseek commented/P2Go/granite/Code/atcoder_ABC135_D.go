
package main
import (
    "bufio"
    "fmt"
    "os"
)
var (
    reader *bufio.Reader
    writer *bufio.Writer
)
func check ( err error ) {
    if err!= nil {
        panic ( err )
    }
}
func main ( ) {
    reader = bufio.NewReader ( os.Stdin )
    writer = bufio.NewWriter ( os.Stdout )
    defer writer.Flush ( )
    var n int
    var s string
    fmt.Fscanf ( reader, "%d\n", & n )
    fmt.Fscanf ( reader, "%s\n", & s )
    if n == 1 {
        if s == "5" || s == "?" {
            fmt.Fprintln ( writer, "1" )
        } else {
            fmt.Fprintln ( writer, "0" )
        }
        return
    }
    dp := make ( [] [] int, n )
    for i := 0; i < n; i ++ {
        dp [ i ] = make ( [] int, 13 )
    }
    for i := 0; i < n; i ++ {
        if i == 0 {
            if s [ i ]!= '?' {
                dp [ i ] [ int ( s [ i ] ) ] += 1
            } else {
                for j := 0; j < 10; j ++ {
                    dp [ i ] [ j ] += 1
                }
            }
        } else {
            if s [ i ]!= '?' {
                for j := 0; j < 13; j ++ {
                    dp [ i ] [ ( j * 10 + int ( s [ i ] ) ) % 13 ] += dp [ i - 1 ] [ j ]
                }
            } else {
                for j := 0; j < 10; j ++ {
                    for k := 0; k < 13; k ++ {
                        dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ]
                    }
                }
            }
            for j := 0; j < 13; j ++ {
                dp [ i ] [ j ] %= 100000007
            }
        }
    }
    fmt.Fprintln ( writer, dp [ n - 1 ] [ 5 ] )
}
