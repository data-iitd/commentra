package main
import "fmt"
func main() {
    var n int
    var s []string
    var flag int
    var d1 []string
    var d2 []string
    var rem map[string]bool
    fmt.Scanf("%d\n", &n)
    for i := 0; i < n; i++ {
        var k string
        fmt.Scanf("%s\n", &k)
        s = append(s, k)
    }
    flag = 0
    d1 = make([]string, 0)
    d2 = make([]string, 0)
    rem = make(map[string]bool)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i == j {
                d1 = append(d1, s[i][j])
            }
            if i == n-j-1 {
                d2 = append(d2, s[i][j])
            }
            if i!= j && i!= n-j-1 {
                rem[s[i][j]] = true
            }
        }
    }
    if len(rem)!= 1 {
        fmt.Println("NO")
    } else if d1!= d2 {
        fmt.Println("NO")
    } else if len(d1)!= 1 {
        fmt.Println("NO")
    } else if d1[0] == "0" {
        fmt.Println("NO")
    } else if _, ok := rem[d1[0]]; ok {
        fmt.Println("NO")
    } else {
        fmt.Println("YES")
    }
}
