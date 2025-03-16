
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

    a := make([]int32, n)

    for i := int32(0); i < n; i++ {
        aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        a[i] = int32(aTemp)
    }

    t := int32(0)

    for i := int32(0); i < n; i++ {
        s := int32(0)

        for j := int32(1); j < n; j++ {
            if j <= i {
                continue
            }

            m := a[i] * a[j]
            s += m
        }

        t += s
    }

    fmt.Println(t)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

