package main
import "fmt"
import "math"
import "strings"
import "strconv"

func main() {
    var N string
    fmt.Scanln(&N)
    S := 0
    for i:=0;i<len(N);i++{
        S += int(N[i]) - '0'
    }
    if int(N)%S == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}
