

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    s, l := readTwoLines()
    m, a, r := initialize(l)
    for i, e := range reverse(s) {
        a += int(e-'0') * int(math.Pow(10, float64(i)))
        r += m[a%l]
        m[a%l]++
    }
    fmt.Println(r)
}

func readTwoLines() (string, int) {
    scanner := bufio.NewScanner(os.Stdin)
    var s string
    scanner.Scan()
    s = scanner.Text()
    var l int
    scanner.Scan()
    l, _ = strconv.Atoi(scanner.Text())
    return s, l
}

func initialize(l int) ([]int, int, int) {
    m := make([]int, l)
    m[0] = 1
    return m, 0, 0
}

func reverse(s string) []rune {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return r
}

