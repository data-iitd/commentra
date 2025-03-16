

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

    aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    a := int32(aTemp)

    bTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    b := int32(bTemp)

    cTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    c := int32(cTemp)

    arr := []int32{a, b, c}

    maxn := int32(4010)
    dp := make([]int32, maxn)

    for i := int32(0); i < n; i++ {
        dp[i] = -100000000
    }

    dp[0] = 0

    for i := 0; i < 3; i++ {
        for j := arr[i]; j < maxn; j++ {
            dp[j] = max(dp[j], dp[j-arr[i]]+1)
        }
    }

    fmt.Println(dp[n])

    fmt.Println("