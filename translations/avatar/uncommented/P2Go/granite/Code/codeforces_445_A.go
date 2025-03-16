
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
    var n, m int
    var err error
    var s string
    var l []string
    if s, err = reader.ReadString('\n'); err!= nil {
        panic(err)
    }
    if n, err = strconv.Atoi(strings.TrimSpace(s)); err!= nil {
        panic(err)
    }
    if s, err = reader.ReadString('\n'); err!= nil {
        panic(err)
    }
    if m, err = strconv.Atoi(strings.TrimSpace(s)); err!= nil {
        panic(err)
    }
    for i := 0; i < n; i++ {
        if s, err = reader.ReadString('\n'); err!= nil {
            panic(err)
        }
        s = strings.TrimSpace(s)
        for j := 0; j < m; j++ {
            if s[j] == '.' {
                if (i+j)%2 == 0 {
                    s = s[:j] + "B" + s[j+1:]
                } else {
                    s = s[:j] + "W" + s[j+1:]
                }
            }
        }
        l = append(l, s)
    }
    for _, c := range l {
        fmt.Println(c)
    }
}
