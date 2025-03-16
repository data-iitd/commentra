

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

    var n int
    var str string
    fmt.Fscan(reader, &n)
    fmt.Fscan(reader, &str)

    a := ""
    for i := 0; i < n/2; i++ {
        a += string(str[i])
    }

    if str == a+a {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

