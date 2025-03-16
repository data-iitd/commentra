

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
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine()[0]))
    x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine()[0]))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadLine()[0]))
    }
    sort.Ints(a)
    ans := 0
    if a[0] > x {
        fmt.Println(0)
        return
    }
    for i := 0; i < n; i++ {
        if a[i] > x {
            x = 0
            break
        }
        if a[i] <= x {
            x -= a[i]
            ans++
        }
    }
    if x!= 0 {
        ans--
    }
    fmt.Println(ans)
}

