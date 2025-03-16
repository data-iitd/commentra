package main

import "fmt"
import "strconv"

func main() {
    var N int
    var i int64
    var c int
    var s string
    var f bool

    fmt.Scanf("%d", &N)
    i = 357
    c = 0

    for i <= N {
        s = strconv.FormatInt(i, 10)
        if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
            c++
        }

        sb := new(strings.Builder)
        f = false
        for j := 0; j < len(s); j++ {
            a := s[len(s)-1-j]
            if f {
                sb.WriteByte(a)
            } else {
                if a == '3' {
                    sb.WriteByte('5')
                    f = true
                } else if a == '5' {
                    sb.WriteByte('7')
                    f = true
                } else {
                    sb.WriteByte('3')
                }
            }
        }
        if!f {
            sb.WriteByte('3')
        }

        sb2 := new(strings.Builder)
        for j := len(sb.String()) - 1; j >= 0; j-- {
            sb2.WriteByte(sb.String()[j])
        }
        i, _ = strconv.ParseInt(sb2.String(), 10, 64)
    }

    fmt.Println(c)
}

