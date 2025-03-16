
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    var l, r int
    fmt.Scanf("%d %d", &l, &r)
    curr := r
    s := 0
    for curr > 0 {
        s += 1
        curr /= 10
    }
    first := int(math.Pow10(s))
    second := first / 2
    ans := -1
    for i := l; i <= r; i++ {
        if i >= l && i <= r {
            curr := i
            rev := ""
            for k := range strings.Split(strconv.Itoa(curr), "") {
                rev += string(9 - int(k[0]))
            }
            ans = int(math.Max(float64(ans), float64(int(rev)*curr)))
        }
    }
    fmt.Println(ans)
}

