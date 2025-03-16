

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
    var err error

    a, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    b, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    count := 0
    for {
        if a > 0 && b > 0 {
            count++
            a--
            b--
        } else {
            break
        }
    }

    ans := a/2 + b/2

    fmt.Println(count, ans)
}

These comments should provide a clear understanding of what each part of the code does.