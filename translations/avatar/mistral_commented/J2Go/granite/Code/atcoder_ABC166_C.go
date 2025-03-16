

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

    NTemp, err := reader.ReadString('\n')
    checkError(err)
    N, err := strconv.ParseInt(strings.TrimSpace(NTemp), 10, 64)
    checkError(err)

    MTemp, err := reader.ReadString('\n')
    checkError(err)
    M, err := strconv.ParseInt(strings.TrimSpace(MTemp), 10, 64)
    checkError(err)

    H := make([]int64, N)

    for i := int64(0); i < N; i++ {
        HTemp, err := reader.ReadString('\n')
        checkError(err)
        H[i], err = strconv.ParseInt(strings.TrimSpace(HTemp), 10, 64)
        checkError(err)
    }

    ans := make([]bool, N)
    for i := int64(0); i < N; i++ {
        ans[i] = true
    }

    for query := int64(0); query < M; query++ {
        temp1Temp, err := reader.ReadString(' ')
        checkError(err)
        temp1, err := strconv.ParseInt(strings.TrimSpace(temp1Temp), 10, 64)
        checkError(err)

        temp2Temp, err := reader.ReadString('\n')
        checkError(err)
        temp2, err := strconv.ParseInt(strings.TrimSpace(temp2Temp), 10, 64)
        checkError(err)

        if H[temp1-1] < H[temp2-1] {
            ans[temp1-1] = false
        } else if H[temp1-1] > H[temp2-1] {
            ans[temp2-1] = false
        } else {
            ans[temp1-1] = false
            ans[temp2-1] = false
        }
    }

    ans2 := int64(0)
    for i := int64(0); i < N; i++ {
        if ans[i] {
            ans2++
        }
    }

    fmt.Println(ans2)

    // 