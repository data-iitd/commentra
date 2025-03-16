
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

    arr := make([]int64, 0)

    for i := int64(0); i < n; i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        a, err := strconv.ParseInt(strings.TrimSpace(aTemp), 10, 64)
        checkError(err)

        if a == 1 {
            arr = append(arr, i)
        }
    }

    if len(arr) == 0 {
        fmt.Println("0")
    } else {
        result := int64(1)

        for i := int64(1); i < int64(len(arr)); i++ {
            result *= arr[int(i)] - arr[int(i-1)]
        }

        fmt.Println(result)
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

