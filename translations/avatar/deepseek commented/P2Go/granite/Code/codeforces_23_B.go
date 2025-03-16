

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
    for i := int32(0); i < n; i++ {
        aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        a := int32(aTemp)
        if a < 2 {
            fmt.Println(0)
        } else {
            fmt.Println(a - 2)
        }
    }
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

