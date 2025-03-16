package main
import "fmt"
func G ( a, b int ) int {
    for a % b!= 0 {
        a, b = b, a % b
    }
    return b
}
func L ( a, b int ) int {
    return a * b / G ( a, b )
}
func main() {
    var x, y, a, b int
    fmt.Scan ( &x, &y, &a, &b )
    lcm := L ( x, y )
    fmt.Println ( b / lcm - ( a - 1 ) / lcm )
}
