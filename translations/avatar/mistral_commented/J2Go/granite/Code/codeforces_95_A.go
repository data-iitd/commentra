

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    n, _ := fmt.Fscanf(reader, "%d\n", &n)

    var s []string
    for i := 0; i < n; i++ {
        var s_ string
        fmt.Fscanf(reader, "%s\n", &s_)
        s = append(s, s_)
    }

    var c string
    fmt.Fscanf(reader, "%s\n", &c)

    var a string
    if c == "a" {
        a = "b"
    } else {
        a = "a"
    }

    var cc string
    fmt.Fscanf(reader, "%s\n", &cc)

    var lucky []bool
    for i := 0; i < len(cc); i++ {
        lucky = append(lucky, false)
    }

    for i := 0; i < len(cc); i++ {
        for j := 0; j < n; j++ {
            if i+len(s[j]) <= len(cc) && strings.EqualFold(cc[i:i+len(s[j])], s[j]) {
                for k := 0; k < len(s[j]); k++ {
                    lucky[i+k] = true
                }
            }
        }
    }

    for i := 0; i < len(cc); i++ {
        if lucky[i] {
            if strings.ToLower(string(cc[i])) == c {
                if strings.ToUpper(string(cc[i])) == c {
                    cc = cc[:i] + strings.ToUpper(a) + cc[i+1:]
                } else {
                    cc = cc[:i] + strings.ToLower(a) + cc[i+1:]
                }
            } else {
                if strings.ToUpper(string(cc[i])) == c {
                    cc = cc[:i] + strings.ToUpper(string(c)) + cc[i+1:]
                } else {
                    cc = cc[:i] + strings.ToLower(string(c)) + cc[i+1:]
                }
            }
        }
    }

    fmt.Println(cc)
}

