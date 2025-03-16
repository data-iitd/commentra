package main
import (
    "fmt"
    "os"
    "strings"
)
func main() {
    var txt string
    var cu, cl int
    fmt.Scanf("%s", &txt)
    for _, z := range txt {
        if strings.ToLower(string(z)) == string(z) {
            cl++
        } else {
            cu++
        }
    }
    if cu > cl {
        out := strings.ToUpper(txt)
    } else {
        out := strings.ToLower(txt)
    }
    fmt.Println(out)
}
