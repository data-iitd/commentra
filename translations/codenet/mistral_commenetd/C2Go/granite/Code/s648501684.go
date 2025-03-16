

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    k := int32(kTemp)

    qTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    q := int32(qTemp)

    arr := make([]int32, n)

    for i := int32(0); i <= n; i++ {
        arr[i] = 0
    }

    for i := int32(0); i < q; i++ {
        tempTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        temp := int32(tempTemp)
        arr[temp] += 1
    }

    for i := int32(1); i <= n; i++ {
        if arr[i] > (q - k) {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

Translate the above Go code to Python and end with comment "