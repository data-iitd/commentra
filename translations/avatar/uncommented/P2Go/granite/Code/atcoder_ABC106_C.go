
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    r = bufio.NewReader ( os.Stdin )
    w = bufio.NewWriter ( os.Stdout )
)

func main ( ) {
    var s string
    var k int
    fmt.Fscanf ( r, "%s\n%d\n", & s, & k )
    l := 0
    for _, c := range s {
        if c!= '1' {
            break
        }
        l += 1
    }
    if l >= k {
        fmt.Fprintln ( w, 1 )
    } else {
        fmt.Fprintln ( w, s [ l ] )
    }
    w.Flush ( )
}

