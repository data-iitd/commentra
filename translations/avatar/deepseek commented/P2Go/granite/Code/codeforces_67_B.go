
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

    nk := strings.Split(readLine(reader), " ")

    nTemp, err := strconv.ParseInt(nk[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(nk[1], 10, 64)
    checkError(err)
    k := int32(kTemp)

    m := readLine(reader)

    mTemp := strings.Split(m, " ")

    var M []int32

    for i := 0; i < int(n); i++ {
        mTempItem, err := strconv.ParseInt(mTemp[i], 10, 64)
        checkError(err)
        mTempItem := int32(mTempItem)
        M = append(M, mTempItem)
    }

    m = 0

    for j := int32(0); j < int32(n); j++ {
        for p := int32(0); p < int32(n); p++ {
            if int32(M[p]) == 0 {
                fmt.Printf("%d ", p+1)
                break
            }
            for l := int32(p + 1 - k); l < p; l++ {
                M[l] -= 1
            }
            M[p] -= 1
        }
    }

    fmt.Println()
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

