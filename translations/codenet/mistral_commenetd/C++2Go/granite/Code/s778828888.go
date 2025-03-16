
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, m, x int
    var err error
    var temp int
    var a [105]int
    var ansl, ansr int
    var i int

    n, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }
    m, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }
    x, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    for i = 0; i < m; i++ {
        temp, err = strconv.Atoi(reader.ReadLine())
        if err!= nil {
            panic(err)
        }
        a[temp] = 1
    }

    for i = x; i <= n; i++ {
        ansr += a[i]
    }

    for i = x; i >= 0; i-- {
        ansl += a[i]
    }

    fmt.Println(min(ansl, ansr))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

