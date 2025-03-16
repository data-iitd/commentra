

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
    arrTemp := strings.Split(nTemp, "\n")[0]
    arr := strings.Split(arrTemp, " ")
    result := int64(1)
    var prevIndex int
    for i := 0; i < int(n); i++ {
        aTemp, err := strconv.ParseInt(arr[i], 10, 64)
        checkError(err)
        a := int(aTemp)
        if a == 1 {
            if prevIndex == 0 {
                prevIndex = i
            } else {
                result *= int64(i - prevIndex)
                prevIndex = i
            }
        }
    }
    fmt.Println(result)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

Translate the above Go code to Python and end with comment "