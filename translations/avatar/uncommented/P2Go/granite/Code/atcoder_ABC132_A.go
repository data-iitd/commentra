
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader ( os.Stdin )
    fmt.Print ( "S = " )
    S, _ := reader.ReadString ( '\n' )
    S = S [ : len ( S ) - 1 ]
    c := make ( map [rune] int )
    for _, i := range S {
        c [ i ] ++
    }
    Sa := make ( map [rune] bool )
    for _, i := range S {
        Sa [ i ] = true
    }
    if len ( Sa )!= 2 {
        fmt.Println ( "No" )
        return
    }
    for _, i := range Sa {
        if c [ i ]!= 2 {
            fmt.Println ( "No" )
            return
        }
    }
    fmt.Println ( "Yes" )
}
