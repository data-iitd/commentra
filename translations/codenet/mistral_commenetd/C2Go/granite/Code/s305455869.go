

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter two integers:")
    aStr, _ := reader.ReadString('\n')
    bStr, _ := reader.ReadString('\n')
    a, _ := strconv.Atoi(strings.TrimSpace(aStr))
    b, _ := strconv.Atoi(strings.TrimSpace(bStr))
    var ans int
    if a >= 13 {
        ans = b
    } else if a >= 6 {
        ans = b / 2
    }
    fmt.Println(ans)
}

// 