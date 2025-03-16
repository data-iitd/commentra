

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
    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)
    FfriendPerDay := make([]int32, 367)
    MfriendPerDay := make([]int32, 367)
    var answer int32 = 0
    for i := 0; i < int(n); i++ {
        inputs := strings.Split(readLine(reader), " ")
        c := inputs[0][0]
        aTemp, err := strconv.ParseInt(inputs[1], 10, 64)
        checkError(err)
        a := int32(aTemp)
        bTemp, err := strconv.ParseInt(inputs[2], 10, 64)
        checkError(err)
        b := int32(bTemp)
        for j := a; j <= b; j++ {
            if c == 'M' {
                MfriendPerDay[j]++
            } else {
                FfriendPerDay[j]++
            }
            if MfriendPerDay[j] < FfriendPerDay[j] {
                if MfriendPerDay[j] > answer {
                    answer = MfriendPerDay[j]
                }
            } else {
                if FfriendPerDay[j] > answer {
                    answer = FfriendPerDay[j]
                }
            }
        }
    }
    fmt.Println(2 * answer)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

