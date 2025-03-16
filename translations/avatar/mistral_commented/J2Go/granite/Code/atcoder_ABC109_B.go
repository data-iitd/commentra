

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

    NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    N := int32(NTemp)

    mapTemp := make([]string, N)

    for i := int32(0); i < N; i++ {
        mapTemp[i], err = readLine(reader)
        checkError(err)
    }

    map_ := make(map[int32]string)

    for i := int32(0); i < N; i++ {
        map_[i] = mapTemp[i]
    }

    past := make(map[int32]string)

    ans := "Yes"

    next := ""

    for i := int32(0); i < N; i++ {
        if _, ok := past[i]; ok {
            ans = "No"
            break
        }
        past[i] = map_[i]

        if i!= 0 {
            if next!= string(map_[i][0]) {
                ans = "No"
                break
            }
        }
        next = string(map_[i][len(map_[i])-1])
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

