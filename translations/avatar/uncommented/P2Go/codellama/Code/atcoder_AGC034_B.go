package main
import "fmt"
func gcd ( a , b int ) int {
    a , b = max ( a , b ) , min ( a , b )
    for a % b > 0 {
        a , b = b , a % b
    }
    return b
}
func solve ( ) {
    var s string
    fmt.Scan ( &s )
    t := ""
    i := 0
    for i < len ( s ) {
        if s [ i ] == 'A' {
            t += "A"
            i += 1
        } else if s [ i ] == 'B' {
            if i < len ( s ) - 1 {
                if s [ i + 1 ] == 'C' {
                    t += "D"
                    i += 2
                } else {
                    t += "X"
                    i += 1
                }
            } else {
                t += "X"
                i += 1
            }
        } else {
            t += "X"
            i += 1
        }
    }
    total := 0
    numA := 0
    for i := 0 ; i < len ( t ) ; i ++ {
        if t [ i ] == 'X' {
            numA = 0
        } else {
            if t [ i ] == 'A' { numA += 1 }
            else { total += numA }
        }
    }
    fmt.Println ( total )
    INF := 10 ** 25
    mod := 7 + 10 ** 9
    return 0
}
func main ( ) {
    solve ( )
}
