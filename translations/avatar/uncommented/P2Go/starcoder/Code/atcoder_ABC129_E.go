package main

import "fmt"

func main() {
    var l string
    fmt.Scan( &l )
    n := len( l )
    dp := make( [][]int, n + 1 )
    for i := 0 ; i <= n ; i++ {
        dp[ i ] = make( []int, 2 )
    }
    dp[ 0 ][ 0 ] = 1
    for i, c := range l {
        if c == '0' {
            dp[ i + 1 ][ 0 ] += dp[ i ][ 0 ]
            dp[ i + 1 ][ 1 ] += dp[ i ][ 1 ] * 3
        } else {
            dp[ i + 1 ][ 0 ] += dp[ i ][ 0 ] * 2
            dp[ i + 1 ][ 1 ] += dp[ i ][ 0 ]
            dp[ i + 1 ][ 1 ] += dp[ i ][ 1 ] * 3
        }
        dp[ i + 1 ][ 0 ] %= 1000000007
        dp[ i + 1 ][ 1 ] %= 1000000007
    }
    fmt.Println( dp[ n ][ 0 ] + dp[ n ][ 1 ] )
}

