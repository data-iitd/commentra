

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

    var nd []string

    nd = strings.Split(readLine(reader), " ")

    nTemp, err := strconv.ParseInt(nd[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    dTemp, err := strconv.ParseInt(nd[1], 10, 64)
    checkError(err)
    d := int32(dTemp)

    x := readLine(reader)

    xSplit := strings.Split(x, " ")

    var xTemp []int32

    for i := 0; i < int(n); i++ {
        xTempItem, err := strconv.ParseInt(xSplit[i], 10, 64)
        checkError(err)
        xTemp = append(xTemp, int32(xTempItem))
    }

    m := int32(0)

    for a := int32(0); a < int32(n-1); a++ {
        if xTemp[a] >= xTemp[a+1] {
            q := int32((xTemp[a] - xTemp[a+1]) / d + 1)

            m = m + q

            xTemp[a+1] = xTemp[a+1] + q * d
        }
    }

    fmt.Println(m)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

