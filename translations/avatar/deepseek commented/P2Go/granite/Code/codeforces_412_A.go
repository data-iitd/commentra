

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
    var v string

    fmt.Fscanf(reader, "%d %d\n", &n, &k)
    fmt.Fscanf(reader, "%s\n", &v)

    d := []string{"LEFT", "RIGHT"}

    f := k-1 < n-k

    m := int(math.Min(float64(k-1), float64(n-k)))

    a := make([]string, 0)

    for i := 0; i < m; i++ {
        a = append(a, d[int(!f)])
    }

    for i := len(v) - 1; i >= 0; i -= 2*f - 1 {
        a = append(a, "PRINT "+string(v[i]))
        a = append(a, d[int(f)])
    }

    for i := len(a) - 1; i >= 0; i-- {
        fmt.Println(a[i])
    }
}

