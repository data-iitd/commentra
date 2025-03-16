

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(nStr)
    ans := 0

    for i := 1; i < n+1; i++ {
        term := n / i
        sum := term * (term + 1) / 2
        ans += i * sum
    }

    fmt.Println(ans)
}

