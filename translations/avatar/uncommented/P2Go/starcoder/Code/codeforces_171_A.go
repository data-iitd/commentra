package main
import "fmt"
import "strings"
func main() {
    var a, b string
    fmt.Scanf("%s %s", &a, &b)
    x := len(a)
    if x < len(b) {
        x = len(b)
    }
    a = strings.Repeat("0", x-len(a)) + a
    b = strings.Repeat("0", x-len(b)) + b
    s := ""
    c := 0
    for i := 0; i < x; i++ {
        d := int(b[i]) + int(a[x-i-1]) + c
        if d > 9 {
            s += string(d%10 + '0')
            c = 1
        } else {
            s += string(d)
            c = 0
        }
    }
    if c == 1 {
        s += "1"
    }
    fmt.Println(strings.TrimRight(s, "0"))
}
