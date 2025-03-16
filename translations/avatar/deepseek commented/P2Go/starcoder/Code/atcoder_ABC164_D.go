
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    s, l := input(), 2019
    m, a, r := []int{1}, 0, 0
    for i, e := range s[:len(s)-1] {
        a += int(e) * int(math.Pow(10, float64(i), float64(l)))
        r += m[a%l]
        m[a%l]++
    }
    fmt.Println(r)
}

func input() string {
    s, _ := strconv.Unquote(strings.Replace(os.ReadLine(), "\n", "", -1))
    return s
}

