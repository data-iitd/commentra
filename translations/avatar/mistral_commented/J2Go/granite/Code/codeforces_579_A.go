

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
    n, _ := strconv.Atoi(reader.ReadLine())
    s := ""
    for n > 0 {
        x := n % 2
        n /= 2
        s = fmt.Sprintf("%d%s", x, s)
    }
    ans := 0
    for _, v := range strings.Split(s, "") {
        if v == "1" {
            ans++
        }
    }
    fmt.Println(ans)
}

// END-OF-CODE