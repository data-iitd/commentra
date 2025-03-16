
package main
import (
    "bufio"
    "fmt"
    "io"
    "log"
    "math"
    "os"
    "strconv"
    "strings"
)
var debug = false
func log(text string) {
    if debug {
        fmt.Println(text)
    }
}
func parse_input(lines_as_string string) (c string) {
    global debug
    lines := strings.Split(lines_as_string, "\n")
    if lines_as_string == "" {
        debug = false
        lines = strings.Split(bufio.NewReader(io.Reader(os.Stdin)).ReadString('\n')[0], "\n")
    } else {
        debug = true
        lines = lines[1 : len(lines)-1]
    }
    c = strings.Split(lines[0], " ")[0]
    return
}
func solve(c string) (result string) {
    a := "abcdefghijklmnopqrstuvwxyz"
    i := strings.Index(a, c)
    result = string(a[i+1])
    return
}
func main() {
    var c string
    c, _ = parse_input("")
    result := solve(c)
    fmt.Println(result)
}
