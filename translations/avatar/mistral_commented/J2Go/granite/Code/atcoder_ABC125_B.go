

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

    vTemp, err := reader.ReadString('\n')
    checkError(err)
    v := strings.Split(strings.TrimSpace(vTemp), " ")

    cTemp, err := reader.ReadString('\n')
    checkError(err)
    c := strings.Split(strings.TrimSpace(cTemp), " ")

    max := int64(0)

    for i := int64(0); i < n; i++ {
        profit, err := strconv.ParseInt(v[i], 10, 64)
        checkError(err)
        cost, err := strconv.ParseInt(c[i], 10, 64)
        checkError(err)
        if profit-cost > 0 {
            max += profit - cost
        }
    }

    fmt.Println(max)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

