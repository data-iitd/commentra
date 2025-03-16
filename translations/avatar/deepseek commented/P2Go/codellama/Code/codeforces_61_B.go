
package main

import (
    "fmt"
    "math"
    "strings"
)

func valid(i, j, n, m int) bool {
    if i < n && i >= 0 && j >= 0 && j < m {
        return true
    }
    return false
}

func sumn(i, n int) int {
    return (n - i) * (i + n) / 2
}

func sqfun(a, b, c float64) float64 {
    return (-b + math.Sqrt(b*b-4*a*c)) / 2 * a
}

func value() (int, int) {
    return value(os.Stdin)
}

func value(r io.Reader) (int, int) {
    var a, b int
    fmt.Fscan(r, &a, &b)
    return a, b
}

func values() (int, int, int) {
    return values(os.Stdin)
}

func values(r io.Reader) (int, int, int) {
    var a, b, c int
    fmt.Fscan(r, &a, &b, &c)
    return a, b, c
}

func inlst() []int {
    return inlst(os.Stdin)
}

func inlst(r io.Reader) []int {
    var a []int
    for {
        var b int
        fmt.Fscan(r, &b)
        a = append(a, b)
        if b == 0 {
            break
        }
    }
    return a
}

func inp() int {
    return inp(os.Stdin)
}

func inp(r io.Reader) int {
    var a int
    fmt.Fscan(r, &a)
    return a
}

func instr() string {
    return instr(os.Stdin)
}

func instr(r io.Reader) string {
    var a string
    fmt.Fscan(r, &a)
    return a
}

func stlst() []string {
    return stlst(os.Stdin)
}

func stlst(r io.Reader) []string {
    var a []string
    for {
        var b string
        fmt.Fscan(r, &b)
        a = append(a, b)
        if b == "" {
            break
        }
    }
    return a
}

func f(s string) string {
    r := ""
    for _, i := range s {
        if i != '-' && i != ';' && i != '_' {
            r += strings.ToLower(string(i))
        }
    }
    return r
}

func solve() {
    l := [3]string{}
    for i := 0; i < 3; i++ {
        l[i] = f(instr())
    }
    t := itertools.Permutations(l[:], len(l))
    l = [][3]string{}
    for i := range t {
        l = append(l, [3]string{t[i][0], t[i][1], t[i][2]})
    }
    for i := 0; i < inp(); i++ {
        if f(instr()) == l[i] {
            fmt.Println("ACC")
        } else {
            fmt.Println("WA")
        }
    }
}

func main() {
    solve()
}

