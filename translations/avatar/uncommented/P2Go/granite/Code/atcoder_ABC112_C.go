
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func solve ( n int, ls_xyh [][] int ) ( string, error ) {
    x0 := 0
    for i := 0 ; i < n ; i ++ {
        if ls_xyh [ i ] [ 2 ] > 0 {
            x0 = ls_xyh [ i ] [ 0 ]
            break
        }
    }
    cands := make ( [] [] int, 0 )
    for cx := 0 ; cx < 101 ; cx ++ {
        for cy := 0 ; cy < 101 ; cy ++ {
            cands = append ( cands, [] int { cx, cy, ls_xyh [ 0 ] [ 2 ] + abs ( cx - x0 ) + abs ( cy - ls_xyh [ 0 ] [ 1 ] ) } )
        }
    }
    for i := 0 ; i < n ; i ++ {
        cands2 := make ( [] [] int, 0 )
        for j := 0 ; j < len ( cands ) ; j ++ {
            if max ( cands [ j ] [ 2 ] - abs ( cands [ j ] [ 0 ] - ls_xyh [ i ] [ 0 ] ) - abs ( cands [ j ] [ 1 ] - ls_xyh [ i ] [ 1 ] ), 0 ) == ls_xyh [ i ] [ 2 ] {
                cands2 = append ( cands2, cands [ j ] )
            }
        }
        cands = cands2
    }
    return fmt.Sprintf ( "%d %d %d", cands [ 0 ] [ 0 ], cands [ 0 ] [ 1 ], cands [ 0 ] [ 2 ] ), nil
}
func readQuestion ( ) ( int, [][] int, error ) {
    reader := bufio.NewReader ( os.Stdin )
    ws, err := reader.ReadString ( '\n' )
    if err!= nil {
        return 0, nil, err
    }
    n, err := strconv.Atoi ( strings.TrimSpace ( ws ) )
    if err!= nil {
        return 0, nil, err
    }
    ls_xyh := make ( [][] int, n )
    for i := 0 ; i < n ; i ++ {
        ws, err := reader.ReadString ( '\n' )
        if err!= nil {
            return 0, nil, err
        }
        ws = strings.TrimSpace ( ws )
        ws = strings.Replace ( ws, "  ", " ", - 1 )
        ws = strings.Replace ( ws, ", ", " ", - 1 )
        ws = strings.Replace ( ws, " [ ", " ", - 1 )
        ws = strings.Replace ( ws, " ] ", " ", - 1 )
        ws = strings.Replace ( ws, " ( ", " ", - 1 )
        ws = strings.Replace ( ws, " ) ", " ", - 1 )
        ws = strings.Replace ( ws, " { ", " ", - 1 )
        ws = strings.Replace ( ws, " } ", " ", - 1 )
        ws = strings.Replace ( ws, " \n ", " ", - 1 )
        ws = strings.Replace ( ws, " \n", " ", - 1 )
        ws = strings.Replace ( ws, "\n ", " ", - 1 )
        ws = strings.Replace ( ws, "\n", " ", - 1 )
        ws = strings.Replace ( ws, "  ", " ", - 1 )
        ws = strings.TrimSpace ( ws )
        ls_xyh [ i ] = make ( [] int, 3 )
        for j := 0 ; j < 3 ; j ++ {
            ls_xyh [ i ] [ j ], err = strconv.Atoi ( strings.TrimSpace ( strings.Split ( ws, " " ) [ j ] )
            if err!= nil {
                return 0, nil, err
            }
        }
    }
    return n, ls_xyh, nil
}
func main ( ) {
    n, ls_xyh, err := readQuestion ( )
    if err!= nil {
        fmt.Println ( err )
        return
    }
    answer, err := solve ( n, ls_xyh )
    if err!= nil {
        fmt.Println ( err )
        return
    }
    fmt.Println ( answer )
}
func abs ( x int ) int {
    if x < 0 {
        return - x
    }
    return x
}
func max ( x int, y int ) int {
    if x > y {
        return x
    }
    return y
}
