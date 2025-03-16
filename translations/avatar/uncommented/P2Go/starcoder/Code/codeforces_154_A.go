package main
import "fmt"
import "os"
import "bufio"
import "strings"

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    n, _ := reader.ReadString('\n')
    n = strings.TrimSpace(n)
    n = int(n)
    ans := 0
    for i := 0; i < n; i++ {
        x, _ := reader.ReadString('\n')
        x = strings.TrimSpace(x)
        a, b := 0, 0
        for _, j := range x {
            if j == x[0] {
                a++
            } else if j == x[1] {
                b++
            } else {
                ans += min(a, b)
                a, b = 0, 0
            }
        }
        ans += min(a, b)
    }
    fmt.Println(ans)
}

