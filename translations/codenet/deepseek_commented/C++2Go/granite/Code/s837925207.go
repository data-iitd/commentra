
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var x int
    var ans int
    var err error

    x, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        fmt.Println("Error reading input:", err)
        return
    }

    ans = x + x*x + x*x*x

    fmt.Println(ans)
}

