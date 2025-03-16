

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function starts here
func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    aTemp := strings.Split(readLine(reader), " ")

    var a []int32

    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        a = append(a, aItem)
    }

    ans := int32(0)

    ok := true

    for ok {
        for i := 0; i < int(n); i++ {
            if a[i]%2 == 1 {
                fmt.Println(ans)
                os.Exit(0)
            } else {
                a[i] = a[i] / 2
            }
        }
        ans++
        ok = false
        for i := 0; i < int(n); i++ {
            if a[i]%2 == 1 {
                ok = true
            }
        }
    }

    fmt.Println(ans)
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

