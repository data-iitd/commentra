package main
import (
    "fmt"
    "os"
)
func solve ( tc int ) {
    a := 0
    fmt.Scan ( &a )
    fmt.Println ( 1 if a == 0 else 0 )
}
func main () {
    tcs := 1
    tc := 1
    for tc <= tcs {
        solve ( tc )
        tc += 1
    }
}
