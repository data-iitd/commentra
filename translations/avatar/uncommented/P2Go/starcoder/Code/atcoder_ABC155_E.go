package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    s := bufio.NewScanner(os.Stdin)
    s.Split(bufio.ScanWords)
    s.Scan()
    s = bufio.NewScanner(strings.NewReader(s.Text()))
    s.Split(bufio.ScanWords)
    var pmin, mmin int
    s.Scan()
    s = bufio.NewScanner(strings.NewReader(s.Text()))
    s.Split(bufio.ScanWords)
    for s.Scan() {
        v, _ := strconv.Atoi(s.Text())
        npmin := min(pmin+10-(v+1), mmin+10-v)
        nmmin := min(pmin+v+1, mmin+v)
        pmin = npmin
        mmin = nmmin
    }
    fmt.Println(min(pmin, mmin))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

