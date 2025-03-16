
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader ( os.Stdin )
    var max_level int
    var x [] int
    var y [] int
    fmt.Fscanf ( reader, "%d\n", & max_level )
    fmt.Fscanf ( reader, "%d\n", & x [ 0 ] )
    fmt.Fscanf ( reader, "%d\n", & y [ 0 ] )
    for i := 1 ; i < x [ 0 ] ; i ++ {
        var tmp int
        fmt.Fscanf ( reader, "%d", & tmp )
        x = append ( x, tmp )
    }
    for i := 1 ; i < y [ 0 ] ; i ++ {
        var tmp int
        fmt.Fscanf ( reader, "%d", & tmp )
        y = append ( y, tmp )
    }
    x = x [ 1 : ]
    y = y [ 1 : ]
    x = remove ( x, 0 )
    y = remove ( y, 0 )
    z := union ( x, y )
    if len ( z )!= max_level {
        fmt.Println ( "Oh, my keyboard!" )
    } else {
        fmt.Println ( "I become the guy." )
    }
}

func remove ( s [] int, e int ) [] int {
    for i, v := range s {
        if v == e {
            s [ i ] = s [ len ( s ) - 1 ]
            return s [ : len ( s ) - 1 ]
        }
    }
    return s
}

func union ( a [] int, b [] int ) [] int {
    m := make ( map [ int ] bool )
    for _, v := range a {
        m [ v ] = true
    }
    for _, v := range b {
        m [ v ] = true
    }
    var result [] int
    for k, _ := range m {
        result = append ( result, k )
    }
    return result
}
