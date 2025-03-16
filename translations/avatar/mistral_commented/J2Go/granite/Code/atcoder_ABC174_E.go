
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
    writer := bufio.NewWriterSize(os.Stdout, 1024*1024)

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

    result := minimumDay(n, k, a)

    fmt.Fprintf(writer, "%d\n", result)

    writer.Flush()
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

func minimumDay(n int32, k int32, a []int32) int32 {
    min := int32(1)
    max := int32(1000000000)

    for min < max {
        mid := (min + max) / 2
        if nei(mid, n, k, a) {
            max = mid
        } else {
            min = mid + 1
        }
    }

    return min
}

func nei(mid int32, n int32, k int32, a []int32) bool {
    daysNeeded := int32(0)

    for i := 0; i < int(n); i++ {
        daysNeeded += (a[i] + mid - 1) / mid
    }

    k -= daysNeeded

    return k >= 0
}

