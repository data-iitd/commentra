
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    var a []int
    var s map[int]int

    reader := bufio.NewReader(os.Stdin)
    n, _ = strconv.Atoi(reader.ReadString('\n'))
    a = make([]int, n)
    s = make(map[int]int)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(reader.ReadString('\n'))
    }

    ng := 0
    ok := n
    for ok-ng > 1 {
        k := (ng + ok) / 2
        if isPossible(k) {
            ok = k
        } else {
            ng = k
        }
    }
    fmt.Println(ok)
}

func isPossible(k int) bool {
    s = make(map[int]int)
    current := 0
    for _, ai := range a {
        if ai <= current {
            if k == 1 {
                return false
            }
            for p := ai - 1; p >= 0; p-- {
                sp := s[p] + 1
                s[p] = sp
                if sp == k {
                    delete(s, p)
                    p--
                } else {
                    break
                }
            }
        }
        current = ai
    }
    return true
}

