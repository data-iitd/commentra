package main
import (
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    var h, a int
    fmt.Scanf("%d %d", &h, &a)
    sho := h / a
    am := h % a
    if am!= 0 {
        sho += 1
    }
    fmt.Println(sho)
}
