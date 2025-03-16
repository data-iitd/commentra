
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    s, l := reader(), 2019
    m, a, r := []int{1}+make([]int, l), 0, 0
    for i, e := range reverse(reader()) {
        a += int(e-'0') * int(math.Pow(10, float64(i)))
        r += m[a%l]
        m[a%l]++
    }
    fmt.Println(r)
}

func reader() string {
    s := bufio.NewScanner(os.Stdin)
    s.Scan()
    return s.Text()
}

func reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

