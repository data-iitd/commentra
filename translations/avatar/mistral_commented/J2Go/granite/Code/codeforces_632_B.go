

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
    aTemp := strings.Split(readLine(reader), " ")
    var a []int32
    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        a = append(a, aItem)
    }
    s := readLine(reader)
    sum := int64(0)
    for i := 0; i < len(s); i++ {
        if s[i] == 'B' {
            sum += int64(a[i])
        }
    }
    ans := sum
    sum1 := sum
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            sum1 += int64(a[i])
        } else {
            sum1 -= int64(a[i])
        }
        if sum1 > ans {
            ans = sum1
        }
    }
    sum1 = sum
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'A' {
            sum1 += int64(a[i])
        } else {
            sum1 -= int64(a[i])
        }
        if sum1 > ans {
            ans = sum1
        }
    }
    fmt.Println(ans)
    // 