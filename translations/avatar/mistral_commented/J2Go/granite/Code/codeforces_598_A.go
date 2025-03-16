
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
    qTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    q := int32(qTemp)
    for qTab := 0; qTab < int(q); qTab++ {
        nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        n := int32(nTemp)
        x := int32(float64(n) / float64(2))
        s := int64(-1*(1<<uint(x+1)) + 2 + (n*(n+1))/2 - (1<<uint(x)))
        fmt.Println(s)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

