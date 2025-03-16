

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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    v := readNInt64s(reader, n)
    vo := make([]int, 100010)
    ve := make([]int, 100010)
    vt := make([]int, 100010)
    for i := 0; i < n; i++ {
        vt[v[i]]++
        if i%2 == 0 {
            ve[v[i]]++
        } else {
            vo[v[i]]++
        }
    }
    sort.Sort(sort.Reverse(sort.IntSlice(vo)))
    sort.Sort(sort.Reverse(sort.IntSlice(ve)))
    sort.Sort(sort.Reverse(sort.IntSlice(vt)))
    ans := 0
    if vo[0]+ve[0] == vt[0] {
        ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0])
    } else {
        ans = n - vo[0] - ve[0]
    }
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
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

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}