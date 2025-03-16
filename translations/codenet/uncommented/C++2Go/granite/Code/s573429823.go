
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Your code here!
    var n uint64
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        var err error
        n, err = strconv.ParseUint(scanner.Text(), 10, 64)
        if err!= nil {
            panic(err)
        }
    }
    flg := false
    if n < 4 {
        fmt.Println("No")
    } else {
        for i := uint64(0); i <= n/4; i++ {
            for j := uint64(0); j <= n/7; j++ {
                if i*4+j*7 == n {
                    flg = true
                    break
                }
            }
            if flg {
                break
            }
        }
        if flg {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
}
