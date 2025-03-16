

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var x, y, a, b int
    var err error

    x, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    y, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    a, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    b, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    count := 0

    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            if i <= j {
                continue
            }
            count++
        }
    }

    fmt.Println(count)

    for i := a; i <= x; i++ {
        for j := b; j <= y; j++ {
            if i <= j {
                continue
            }
            fmt.Printf("%d %d\n", i, j)
        }
    }
}

