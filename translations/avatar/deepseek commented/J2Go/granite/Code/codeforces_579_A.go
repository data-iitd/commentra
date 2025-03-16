
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
    fmt.Print("Enter an integer: ")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))
    s := ""
    for n > 0 {
        x := n % 2
        n /= 2
        s = fmt.Sprintf("%d%s", x, s)
    }
    ans := 0
    for _, v := range s {
        if v == '1' {
            ans++
        }
    }
    fmt.Println(ans)
}

