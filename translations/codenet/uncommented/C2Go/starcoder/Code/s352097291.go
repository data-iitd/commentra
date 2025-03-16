package main
import "fmt"
import "strings"
func main() {
    var c,ans string
    fmt.Scanf("%s\n", &c)
    for i:=0;c[i]!='\0';i++{
        if c[i]!='B' {
            ans += c[i:i+1]
        } else {
            ans = ans[:len(ans)-1]
        }
    }
    fmt.Printf("%s\n", ans)
}
