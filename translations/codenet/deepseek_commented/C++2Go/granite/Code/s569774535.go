
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
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)

    aTemp := strings.Split(nTemp, "\n")[0]
    a := strings.Split(aTemp, " ")[1:]

    var ans int64 = 0
    ok := true
    for ok {
        for _, v := range a {
            i, err := strconv.ParseInt(v, 10, 64)
            checkError(err)
            if i%2 == 1 {
                fmt.Println(ans)
                return
            } else {
                i /= 2
                a[strings.Index(aTemp, v)] = strconv.FormatInt(i, 10)
            }
        }
        ans++
    }

    fmt.Println(ans)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

