

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var t int
    var err error
    for fmt.Fscanf(reader, "%d\n", &t); t > 0; t-- {
        var n int
        var s string
        fmt.Fscanf(reader, "%d\n", &n)
        fmt.Fscanf(reader, "%s\n", &s)

        var sb strings.Builder
        for i := 1; i < n; i++ {
            sb.WriteString(strconv.Itoa(int(s[i]) - int(s[i-1])))
        }

        if n == 2 {
            fmt.Fprintln(writer, s[0])
            continue
        }

        s = sb.String()

        if strings.Contains(s, "1") {
            fmt.Fprintln(writer, cal(s, '1'))
            continue
        }

        fmt.Fprintln(writer, cal(s, '2')*2)
    }

    writer.Flush()
}

func cal(s string, c byte) int {
    n := len(s)
    m := n - 1
    ans := 0

    for i := 0; i < n; i++ {
        if s[i] == c && (m&i) == i {
            ans ^= 1
        }
    }

    return ans
}

// Translate the above Go code to C++ and end with comment "