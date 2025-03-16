
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
    n, m, s, f := read_ints()
    var d, c int
    if s < f {
        d = 1
        c = 'R'
    } else {
        d = -1
        c = 'L'
    }
    res := ""
    i, j := 1, s
    t, l, r := read_ints()
    k := 1
    for j!= f {
        if i > t && k < m {
            t, l, r = read_ints()
            k++
        }
        if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
            res += "X"
        } else {
            res += string(c)
            j += d
        }
        i++
    }
    fmt.Println(res)
}

func read_ints() (n int, m int, s int, f int) {
    s := read_str()
    t := strings.Split(s, " ")
    n, _ = strconv.Atoi(t[0])
    m, _ = strconv.Atoi(t[1])
    s, _ = strconv.Atoi(t[2])
    f, _ = strconv.Atoi(t[3])
    return
}

func read_str() (s string) {
    s, _ = in.ReadString('\n')
    s = strings.TrimSpace(s)
    return
}

func read_str_array(n int) (a []string) {
    for i := 0; i < n; i++ {
        a = append(a, read_str())
    }
    return
}

func read_int_array(n int) (a []int) {
    for i := 0; i < n; i++ {
        a = append(a, read_int())
    }
    return
}

func read_int() (n int) {
    s := read_str()
    n, _ = strconv.Atoi(s)
    return
}

