
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

func S ( ) string {
    var s string
    fmt.Fscanf ( r, "%s", & s )
    return s
}

func I ( ) int64 {
    var x int64
    fmt.Fscanf ( r, "%d", & x )
    return x
}

func LI ( ) [] int64 {
    var a [] int64
    fmt.Fscanf ( r, "%d", & a [ 0 ] )
    for i := 1 ; i < len ( a ) ; i ++ {
        fmt.Fscanf ( r, "%d", & a [ i ] )
    }
    return a
}

func main ( ) {
    a, b := I ( ), I ( )
    if a > 0 {
        fmt.Fprintln ( w, "Positive" )
    } else if a <= 0 && b >= 0 {
        fmt.Fprintln ( w, "Zero" )
    } else {
        if ( a + b ) % 2 == 0 {
            fmt.Fprintln ( w, "Negative" )
        } else {
            fmt.Fprintln ( w, "Positive" )
        }
    }
    w. Flush ( )
}

