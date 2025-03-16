
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    nTemp, err := strconv.ParseInt(readln(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)
    arrTemp := strings.Split(readln(reader), " ")
    var arr []int32
    for _, arrTempItem := range arrTemp {
        arrItemTemp, err := strconv.ParseInt(arrTempItem, 10, 64)
        checkError(err)
        arrItem := int32(arrItemTemp)
        arr = append(arr, arrItem)
    }
    ans := arr[0] + 1
    for i := 1; i < int(n); i++ {
        ans += int32(math.Abs(float64(arr[i]-arr[i-1]))) + 2
    }
    fmt.Println(ans)
}

func readln(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

