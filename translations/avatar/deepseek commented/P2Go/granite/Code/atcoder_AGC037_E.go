

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, k int
    var s string
    fmt.Fscanf(reader, "%d %d\n", &n, &k)
    s, _ = fmt.Fscanf(reader, "%s\n", &s)
    aaaa := false
    if k >= 15 {
        aaaa = true
    } else if 1<<uint(k) >= n {
        aaaa = true
    }
    if aaaa {
        fmt.Println(strings.Repeat(string(s[0]), n))
        return
    }
    u := s + strings.Reverse(s)
    c := s[0]
    p := strings.Index(u, string(c))
    minindex := p
    p++
    for p <= n {
        if u[p] == c {
            if checkNormalDict(u, minindex, p) {
                minindex = p
            }
        }
        p++
    }
    s = u[minindex : minindex+n]
    if k == 1 {
        fmt.Println(s)
        return
    }
    count := 0
    for _, v := range s {
        if v == s[0] {
            count++
        } else {
            break
        }
    }
    if count*(1<<uint(k-1)) >= n {
        fmt.Println(strings.Repeat(string(s[0]), n))
        return
    }
    s = strings.Repeat(string(s[0]), count*(1<<uint(k-1))-1)+s
    fmt.Println(s[:n])
}

func get_last_dict(s string) string {
    u := s + strings.Reverse(s)
    c := s[0]
    p := strings.Index(u, string(c))
    minindex := p
    p++
    for p <= len(s) {
        if u[p] == c {
            if checkNormalDict(u, minindex, p) {
                minindex = p
            }
        }
        p++
    }
    return u[minindex : minindex+len(s)]
}

func checkNormalDict(u string, pointer1, pointer2 int) bool {
    for i := 0; i < len(u); i++ {
        if u[pointer1+i] > u[pointer2+i] {
            return true
        } else if u[pointer1+i] < u[pointer2+i] {
            return false
        }
    }
    return false
}

// 