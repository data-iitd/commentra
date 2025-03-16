
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

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    k := int32(kTemp)

    aTemp := strings.Split(readLine(reader), " ")

    var a []int32

    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        a = append(a, aItem)
    }

    sort.Ints(a)

    var sum int32 = 0

    for i := 0; i < int(k); i++ {
        sum += a[i]
    }

    fmt.Println(sum)

    // 