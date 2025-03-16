
package main

import (
    "bufio"
    "bytes"
    "container/ring"
    "fmt"
    "io"
    "os"
    "sort"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    inf = int64(0x3f3f3f3f)
)

func main() {
    var n, ta, ao int
    fmt.Fscanf(in, "%d%d%d\n", &n, &ta, &ao)
    ta--
    ao--
    g := make([][]int, n)
    for i := 0; i < n-1; i++ {
        var a, b int
        fmt.Fscanf(in, "%d%d\n", &a, &b)
        a--
        b--
        g[a] = append(g[a], b)
        g[b] = append(g[b], a)
    }
    taDist := make([]int, n)
    aoDist := make([]int, n)
    var dfs func(int, int)
    dfs = func(u, d int) {
        taDist[u] = d
        for _, v := range g[u] {
            if taDist[v] == -1 {
                dfs(v, d+1)
            }
        }
    }
    dfs(ta, 0)
    dfs(ao, 0)
    res := 0
    for i := 0; i < n; i++ {
        if taDist[i] > aoDist[i] {
            continue
        }
        res = max(res, aoDist[i])
    }
    fmt.Println(res - 1)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func pow(a, b int) int {
    r := 1
    for b > 0 {
        if b&1 == 1 {
            r *= a
        }
        a *= a
        b >>= 1
    }
    return r
}

func pow64(a, b int64) int64 {
    r := int64(1)
    for b > 0 {
        if b&1 == 1 {
            r *= a
        }
        a *= a
        b >>= 1
    }
    return r
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
    bytes, _ := reader.ReadBytes('\n')
    readInt(bytes, 0, &a)
    return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    res := readNNums(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
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

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
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

func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    for i := 0; i < len(s); i++ {
        if s[i] == '\n' {
            return s[:i]
        }
    }
    return s
}

func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    readInt(bs, 0, &a)
    return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    res := readNNums(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
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

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
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

func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    for i := 0; i < len(s); i++ {
        if s[i] == '\n' {
            return s[:i]
        }
    }
    return s
}

func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    readInt(bs, 0, &a)
    return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    res := readNNums(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
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

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
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

func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    for i := 0; i < len(s); i++ {
        if s[i] == '\n' {
            return s[:i]
        }
    }
    return s
}

func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    readInt(bs, 0, &a)
    return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    res := readNNums(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
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

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
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

func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    for i := 0; i < len(s); i++ {
        if s[i] == '\n' {
            return s[:i]
        }
    }
    return s
}

func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    readInt(bs, 0, &a)
    return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    res := readNNums(reader, 3)
    a, b, c = res[0], res[1], res[2]
    return
}

func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < n; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = rea