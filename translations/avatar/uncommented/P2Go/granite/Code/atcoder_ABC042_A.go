
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
    fmt.Println ( "Enter 3 numbers separated by space: " )
    input, _ := reader.ReadString ( '\n' )
    input = strings.TrimSpace ( input )
    numbers := strings.Split ( input, " " )
    var a, b, c int
    for i := 0 ; i < 3 ; i ++ {
        number, _ := strconv.Atoi ( numbers [ i ] )
        switch i {
        case 0:
            a = number
        case 1:
            b = number
        case 2:
            c = number
        }
    }
    if a == 5 && b == 5 || a == 5 && c == 5 || b == 5 && c == 5 {
        if a + b + c == 17 {
            fmt.Println ( "YES" )
        } else {
            fmt.Println ( "NO" )
        }
    } else {
        fmt.Println ( "NO" )
    }
}
