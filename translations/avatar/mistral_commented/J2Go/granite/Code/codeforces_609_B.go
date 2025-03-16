
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

    mTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    m := int32(mTemp)

    arrTemp := strings.Split(readLine(reader), " ")

    var arr []int32

    for i := 0; i < int(n); i++ {
        arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
        checkError(err)
        arrItem := int32(arrItemTemp)
        arr = append(arr, arrItem)
    }

    gen := make([]int32, 11)

    for i := 0; i < int(n); i++ {
        gen[arr[i]]++
    }

    var ans int64

    for i := 1; i <= m; i++ {
        for k := 1; k <= m; k++ {
            if i!= k {
                ans += int64(gen[i]) * int64(gen[k])
            }
        }
    }

    fmt.Println(ans / 2)
}

func readLine(reader *bufio.Reader) string {
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

