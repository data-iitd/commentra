package main
import "fmt"
func main() {
    // Your code here!
    var n uint64
    fmt.Scanf("%d", &n)
    if n < 4 {
        fmt.Println("No")
    } else {
        for i := uint64(0); i <= n/4; i++ {
            for j := uint64(0); j <= n/7; j++ {
                if i*4+j*7 == n {
                    fmt.Println("Yes")
                    return
                }
            }
        }
        fmt.Println("No")
    }
}
