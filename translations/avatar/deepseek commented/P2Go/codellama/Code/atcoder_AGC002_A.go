package main
import "fmt"
func main() {
    var a, b int
    fmt.Scan(&a, &b)
    if a > 0 {
        fmt.Println("Positive")
    } else if a <= 0 && b >= 0 {
        fmt.Println("Zero")
    } else {
        if (a + b) % 2 == 0 {
            fmt.Println("Negative")
        } else {
            fmt.Println("Positive")
        }
    }
}


Translate the above Go code to C++ and end with comment "