

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

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    qTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    q := int32(qTemp)

    left := make([]int32, n)
    right := make([]int32, n)
    win := make([]int32, n)

    for i := int32(0); i < n; i++ {
        left[i] = i
        right[i] = i
        win[i] = -1
    }

    for i := int32(0); i < q; i++ {
        lrws := strings.Split(readLine(reader), " ")

        lTemp, err := strconv.ParseInt(lrws[0], 10, 64)
        checkError(err)
        l := int32(lTemp) - 1

        rTemp, err := strconv.ParseInt(lrws[1], 10, 64)
        checkError(err)
        r := int32(rTemp) - 1

        wTemp, err := strconv.ParseInt(lrws[2], 10, 64)
        checkError(err)
        w := int32(wTemp) - 1

        for j := l; j <= r; j++ {
            if win[j] == -1 {
                win[j] = w
            }
        }

        if win[w] == -1 {
            win[w] = 0
        }

        for j := l; j <= r; j++ {
            if win[j] == w {
                win[j] = 0
            }
        }
    }

    for i := int32(0); i < n; i++ {
        fmt.Printf("%d ", win[i])
    }

    fmt.Println("")
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

