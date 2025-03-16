
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    N := int32(NTemp)

    LTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    L := int32(LTemp)

    RTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    R := int32(RTemp)

    QLTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    QL := int32(QLTemp)

    QRTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    QR := int32(QRTemp)

    W := make([]int32, N)

    for i := 0; i < int(N); i++ {
        WTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        W[i] = int32(WTemp)
    }

    sum := make([]int64, N+1)

    for i := 0; i < int(N); i++ {
        sum[i+1] = sum[i] + int64(W[i])
    }

    min := int64(9223372036854775807)

    for firstR := int32(0); firstR <= N; firstR++ {
        lCount := firstR
        rCount := N - lCount

        cand := int64(sum[lCount]) * int64(L) + (int64(sum[N]) - int64(sum[lCount])) * int64(R)

        llCount := int32(0)
        if lCount > rCount {
            llCount = lCount - rCount - 1
        }

        rrCount := int32(0)
        if rCount > lCount {
            rrCount = rCount - lCount - 1
        }

        cand += int64(llCount) * int64(QL)
        cand += int64(rrCount) * int64(QR)

        if cand < min {
            min = cand
        }
    }

    fmt.Println(min)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

