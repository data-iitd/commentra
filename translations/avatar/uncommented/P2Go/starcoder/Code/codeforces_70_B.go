package main
import (
    "bufio"
    "fmt"
    "os"
    "regexp"
    "strconv"
    "strings"
)
func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    s := bufio.NewScanner(os.Stdin)
    s.Scan()
    s = bufio.NewScanner(strings.NewReader(s.Text() + "."))
    var ans, sumL int
    for s.Scan() {
        s := s.Text() + "."
        L := len(s)
        if L > 1 {
            if L > n {
                fmt.Println("Impossible")
                return
            }
            if sumL + L + (sumL > 0) > n {
                ans += 1
                sumL = L
            } else {
                sumL = sumL + L + (sumL > 0)
        }
    }
    fmt.Println(ans)
}
