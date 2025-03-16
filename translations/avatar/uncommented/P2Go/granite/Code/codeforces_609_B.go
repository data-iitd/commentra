
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader( os.Stdin )
    out = bufio.NewWriter( os.Stdout )
)

func main ( ) {
    var n, m int
    var lst [ ] int
    var l = make ( map [ int ] int )
    var res int
    var err error
    var s string
    if s, err = in.ReadString ( '\n' ) ; err!= nil { panic ( err ) }
    n, _ = strconv.Atoi ( strings.TrimSpace ( s ) )
    if s, err = in.ReadString ( '\n' ) ; err!= nil { panic ( err ) }
    m, _ = strconv.Atoi ( strings.TrimSpace ( s ) )
    for i := 0 ; i < n ; i ++ {
        if s, err = in.ReadString ('' ) ; err!= nil { panic ( err ) }
        lst [ i ], _ = strconv.Atoi ( strings.TrimSpace ( s ) )
        if lst [ i ], ok := l [ lst [ i ] ] ; ok {
            l [ lst [ i ] ] = lst [ i ] + 1
        } else {
            l [ lst [ i ] ] = 1
        }
    }
    for i := 0 ; i < n ; i ++ {
        if lst [ i ], ok := l [ lst [ i ] ] ; ok {
            if lst [ i ] > 1 {
                res += n - i - lst [ i ]
                l [ lst [ i ] ] = lst [ i ] - 1
            } else {
                res += n - i - 1
            }
        }
    }
    fmt.Fprintln ( out, res )
    out.Flush ( )
}
