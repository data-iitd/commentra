
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    var ans int64
    str, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(str)
    for i := 1; i <= n; i++ {
        ans += int64(i) * (n / i) * ((n / i) + 1) / 2
    }
    fmt.Println(ans)
}

