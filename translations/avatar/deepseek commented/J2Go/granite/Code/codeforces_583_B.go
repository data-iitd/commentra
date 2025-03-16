

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
    for {
        nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        n := int32(nTemp)
        if n == 0 {
            break
        }
        aTemp := strings.Split(readLine(reader), " ")
        var a []int32
        for _, aTempItem := range aTemp {
            aItemTemp, err := strconv.ParseInt(aTempItem, 10, 64)
            checkError(err)
            aItem := int32(aItemTemp)
            a = append(a, aItem)
        }
        b := make([]int32, n)
        s := int32(-1)
        tem := int32(1)
        q := int32(0)
        for q!= n {
            s++
            if tem == 1 {
                for i := int32(0); i < n; i++ {
                    if a[i] <= q && b[i] == 0 {
                        b[i] = 1
                        q++
                    }
                }
                tem = 0
            } else {
                for i := n - 1; i >= 0; i-- {
                    if a[i] <= q && b[i] == 0 {
                        b[i] = 1
                        q++
                    }
                }
                tem = 1
            }
        }
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

