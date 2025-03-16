

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var a, b int
    var count int = 0
    var ans int

    // Loop continues until the condition is met to break
    for {
        aStr, _ := reader.ReadString('\n')
        bStr, _ := reader.ReadString('\n')
        a, _ = strconv.Atoi(aStr)
        b, _ = strconv.Atoi(bStr)
        if a > 0 && b > 0 {
            count++
            a--
            b--
        } else {
            break
        }
    }

    ans = a/2 + b/2
    fmt.Println(count, ans)
}

