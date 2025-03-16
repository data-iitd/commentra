
package main
import (
    "fmt"
    "strings"
)
func main() {
    c := strings.Split(strings.TrimSpace(readLine()), " ")[0]
    fmt.Printf("%s\n", solve(c))
}
func readLine() string {
    buf := make([]byte, 0, 1024)
    for {
        line, prefix, err := bufio.NewReader(os.Stdin).ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if!prefix {
            break
        }
    }
    return string(buf)
}
func solve(c string) string {
    a := "abcdefghijklmnopqrstuvwxyz"
    i := strings.Index(a, c)
    return a[i+1:]
}
