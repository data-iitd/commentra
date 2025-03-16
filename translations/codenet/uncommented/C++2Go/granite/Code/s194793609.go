
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
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))

    aStrs, _ := reader.ReadString('\n')
    aStrs = strings.TrimSpace(aStrs)
    aStrs = aStrs[:len(aStrs)-1]
    aStrsSplit := strings.Split(aStrs, " ")
    a := make([]int64, n)
    for i, str := range aStrsSplit {
        a[i], _ = strconv.ParseInt(str, 10, 64)
    }

    absA := make([]int64, n)
    for i, num := range a {
        if num < 0 {
            absA[i] = -num
        } else {
            absA[i] = num
        }
    }

    ans := int64(0)
    min := absA[0]
    for _, num := range absA {
        ans += num
        if min > num {
            min = num
        }
    }
    numNegative := 0
    for _, num := range a {
        if num < 0 {
            numNegative++
        }
    }

    if numNegative%2!= 0 {
        ans -= min * 2
    }

    fmt.Println(ans)
}
