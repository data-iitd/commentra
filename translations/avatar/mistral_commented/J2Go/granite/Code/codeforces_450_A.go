

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

    mTemp, err := reader.ReadString('\n')
    checkError(err)
    m, err := strconv.ParseInt(strings.TrimSpace(mTemp), 10, 64)
    checkError(err)

    q1 := make([]int64, 0)
    q2 := make([]int64, 0)

    for i := int64(1); i <= n; i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        a, err := strconv.ParseInt(strings.TrimSpace(aTemp), 10, 64)
        checkError(err)
        q1 = append(q1, a)
        q2 = append(q2, i)
    }

    ans := int64(0)

    for len(q1) > 0 {
        if q1[0] <= m {
            ans = q2[0]
            q1 = q1[1:]
            q2 = q2[1:]
        } else {
            x := q1[0]
            q1 = q1[1:]
            val := x - m
            q1 = append(q1, val)
            val2 := q2[0]
            q2 = q2[1:]
            q2 = append(q2, val2)
        }
    }

    fmt.Println(ans)

    // 