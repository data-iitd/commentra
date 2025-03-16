
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, x := na()
    a := sorted(na())
    ans := 0
    if a[0] > x {
        fmt.Println(0)
        return
    }
    for _, i := range a {
        if i > x {
            x = 0
            break
        }
        x -= i
        ans++
    }
    if x!= 0 {
        ans--
    }
    fmt.Println(ans)
}

func na() (int, int) {
    s := read()
    a, _ := strconv.Atoi(s[0])
    b, _ := strconv.Atoi(s[1])
    return a, b
}

func sorted(a []int) []int {
    for i := 0; i < len(a); i++ {
        for j := i + 1; j < len(a); j++ {
            if a[i] > a[j] {
                a[i], a[j] = a[j], a[i]
            }
        }
    }
    return a
}

func read() []string {
    s, _ := in.ReadString('\n')
    s = strings.TrimSpace(s)
    return strings.Split(s, " ")
}

func readi() []int {
    s := read()
    a := make([]int, len(s))
    for i, v := range s {
        a[i], _ = strconv.Atoi(v)
    }
    return a
}

func readf() []float64 {
    s := read()
    a := make([]float64, len(s))
    for i, v := range s {
        a[i], _ = strconv.ParseFloat(v, 64)
    }
    return a
}

func debug(args...interface{}) {
    cfg, _ := os.UserConfigDir()
    f, _ := os.Create(fmt.Sprintf("%s/debug.log", cfg))
    defer f.Close()

    fmt.Fprintln(f, args...)
}

