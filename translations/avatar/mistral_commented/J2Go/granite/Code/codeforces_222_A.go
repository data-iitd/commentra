
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    k := int32(kTemp)

    l := int32(0)
    c := int32(1)

    for i := int32(0); i < n; i++ {
        aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        a := int32(aTemp)

        if a == l {
            c = c + 1
        } else {
            c = 1
        }

        l = a
    }

    if c+k > n {
        fmt.Println(n - c)
    } else {
        fmt.Println(-1)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

