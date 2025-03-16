
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
    fmt.Print("Enter the value of n: ")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))

    p := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Print("Enter the value of p[" + strconv.Itoa(i) + "]: ")
        text, _ := reader.ReadString('\n')
        p[i], _ = strconv.Atoi(strings.TrimSpace(text))
    }

    ans := 0
    for i := 0; i < n-1; i++ {
        if p[i] == i+1 {
            p[i+1] = p[i]
            ans++
        }
    }
    if p[n-1] == n {
        ans++
    }
    fmt.Println(ans)
}
