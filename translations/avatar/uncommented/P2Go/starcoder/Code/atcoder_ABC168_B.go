package main
import "fmt"
func main() {
    var K int
    fmt.Scanf("%d", &K)
    var S string
    fmt.Scanf("%s", &S)
    if len(S) <= K {
        fmt.Println(S)
        return
    }
    fmt.Println(S[:K] + "...")
}
