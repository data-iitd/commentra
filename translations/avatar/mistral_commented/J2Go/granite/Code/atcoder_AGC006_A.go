
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

var (
    N int = 200 + 10
    f [N]int
    b [N]byte
)

func getFail(b []byte, m int) {
    j := 0
    f[0] = f[1] = 0
    for i := 2; i <= m; i++ {
        for j > 0 && b[j+1]!= b[i] {
            j = f[j]
        }
        if b[j+1] == b[i] {
            j++
        }
        f[i] = j
    }
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    s1 := reader.ReadLine()[2:]
    str := reader.ReadLine()[2:]

    cnt := 0
    for i := 0; i < n; i++ {
        b[cnt+1] = str[i]
        cnt++
    }
    for i := 0; i < n; i++ {
        b[cnt+1] = s1[i]
        cnt++
    }

    getFail(b, cnt)

    len := int(min(float64(f[cnt]), float64(n), float64(n)))

    fmt.Fprintf(writer, "%d\n", 2*n-len)

    writer.Flush()
}

func min(a, b, c float64) float64 {
    if a <= b && a <= c {
        return a
    }
    if b <= a && b <= c {
        return b
    }
    return c
}

// END-OF-CODE