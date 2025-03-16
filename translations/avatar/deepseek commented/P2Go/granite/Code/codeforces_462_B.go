

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nk := strings.Split(readLine(reader), " ")

    nTemp, err := strconv.ParseInt(nk[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(nk[1], 10, 64)
    checkError(err)
    k := int32(kTemp)

    s := readLine(reader)

    count := make([]int32, 26)

    for _, c := range s {
        count[c-'A']++
    }

    sort.Slice(count, func(i, j int) bool {
        return count[i] > count[j]
    })

    res := int32(0)

    for i := 0; i < 26; i++ {
        if count[i] >= k {
            res += k * k
            fmt.Println(res)
            return
        }

        k -= count[i]
        res += count[i] * count[i]
    }

    fmt.Println(res)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }

    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

