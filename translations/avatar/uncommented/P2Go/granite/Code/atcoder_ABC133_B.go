
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, d := readTwoInt64s(reader)
    points := make([][]int64, n)
    for i := int64(0); i < n; i++ {
        points[i] = readNInt64s(reader, d)
    }
    count := 0
    for i := int64(0); i < n; i++ {
        for j := int64(i + 1); j < n; j++ {
            if isInteger(dist(points[i], points[j])) {
                count++
            }
        }
    }
    fmt.Println(count)
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    tmp := 0
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int(bytes[i]-'0')
        i++
    }
    *val = tmp * sign
    return i
}

func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    readInt(bs, 0, &a)
    return
}

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
    res := readNInt64s(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeInt64s(reader *bufio.Reader) (a int64, b int64, c int64) {
    res := readNInt64s(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < n; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = readInt(bs, x, &res[i])
    }
    return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
    i := from

    var tmp uint64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + uint64(bytes[i]-'0')
        i++
    }
    *val = tmp

    return i
}

func readInt64(bytes []byte, from int, val *int64) int {
    i := from
    var tmp int64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int64(bytes[i]-'0')
        i++
    }
    *val = tmp
    return i
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
    res := make([]uint64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readUint64(s, pos, &res[i])
    }

    return res
}

func readInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
}

func dist(a, b []int64) float64 {
    var res float64
    for i := 0; i < len(a); i++ {
        res += math.Pow(float64(a[i]-b[i]), 2)
    }
    return math.Sqrt(res)
}

func isInteger(num float64) bool {
    return math.Abs(num-math.Trunc(num)) < 0.000001
}
