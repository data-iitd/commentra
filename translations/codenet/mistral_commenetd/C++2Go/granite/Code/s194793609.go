

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

    a := make([]int64, n)

    for i := int64(0); i < n; i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        aTemp = strings.TrimSpace(aTemp)
        a[i], err = strconv.ParseInt(aTemp, 10, 64)
        checkError(err)
    }

    absA := make([]int64, n)
    for i := int64(0); i < n; i++ {
        if a[i] < 0 {
            absA[i] = -a[i]
        } else {
            absA[i] = a[i]
        }
    }

    ans := int64(0)
    min := absA[0]
    for i := int64(0); i < n; i++ {
        ans += absA[i]
        if min > absA[i] {
            min = absA[i]
        }
    }

    numNegative := int64(0)
    for i := int64(0); i < n; i++ {
        if a[i] < 0 {
            numNegative++
        }
    }

    if numNegative%2!= 0 {
        ans -= min * 2
    }

    fmt.Println(ans)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

