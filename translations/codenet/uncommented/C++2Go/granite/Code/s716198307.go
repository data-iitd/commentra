
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
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        aStr, _ := reader.ReadString('\n')
        a[i], _ = strconv.Atoi(strings.TrimSpace(aStr))
    }
    avg := 0
    for _, v := range a {
        avg += v
    }
    avg /= n
    s := float64(abs(a[0]-avg))
    ans := 0
    for i := 1; i < n; i++ {
        if s > float64(abs(a[i]-avg)) {
            s = float64(abs(a[i]-avg))
            ans = i
        }
    }
    fmt.Println(ans)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

