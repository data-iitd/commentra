
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var pandu, vundu, urdu, c int64
    var err error

    pandu, err = strconv.ParseInt(reader.ReadLine(), 10, 64)
    if err!= nil {
        fmt.Println(err)
        return
    }

    vundu, err = strconv.ParseInt(reader.ReadLine(), 10, 64)
    if err!= nil {
        fmt.Println(err)
        return
    }

    urdu, err = strconv.ParseInt(reader.ReadLine(), 10, 64)
    if err!= nil {
        fmt.Println(err)
        return
    }

    for i := int64(1); i <= urdu; i++ {
        c += i * pandu
    }

    if c < vundu {
        fmt.Println("0")
    } else {
        fmt.Println(c - vundu)
    }
}

