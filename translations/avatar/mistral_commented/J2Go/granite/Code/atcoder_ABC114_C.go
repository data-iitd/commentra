

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    scanner *bufio.Scanner
    N       int64
    i       int64
    c       int
)

func init() {
    scanner = bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)
}

func main() {
    fmt.Fscanf(scanner, "%d\n", &N)

    i = 357
    c = 0

    for i <= N {
        s := strconv.FormatInt(i, 10)

        if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
            c++
        }

        sb := strings.Builder{}
        f := false

        for j := len(s) - 1; j >= 0; j-- {
            a := string(s[j])

            if f {
                sb.WriteString(a)
            } else {
                switch a {
                case "3":
                    sb.WriteString("5")
                    f = true
                case "5":
                    sb.WriteString("7")
                    f = true
                default:
                    sb.WriteString("3")
                    f = true
                }
            }
        }

        if!f {
            sb.WriteString("3")
        }

        s2 := sb.String()
        i, _ = strconv.ParseInt(s2, 10, 64)
    }

    fmt.Println(c)
}

Translate the above Go code to C++ and end with comment "