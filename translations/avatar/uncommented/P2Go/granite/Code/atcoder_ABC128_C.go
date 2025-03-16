
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
    n, m := readTwoNums(reader)
    li := make([][]int, m)
    for i := 0; i < m; i++ {
        li[i] = readNNums(reader, n-1)
    }
    p := readNNums(reader, n)
    q := make(map[int]bool)
    for i := 1; i <= n; i++ {
        q[i] = true
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n-1; j++ {
            if q[li[i][j]] {
                delete(q, li[i][j])
            }
        }
    }
    v := make([]int, 0, len(q))
    for k := range q {
        v = append(v, k)
    }
    ans := 0
    for i := 0; i <= len(q); i++ {
        for s := 0; s < (1 << len(v)); s++ {
            ok := true
            for j := 0; j < m; j++ {
                cnt := 0
                for k := 0; k < n-1; k++ {
                    if q[li[j][k]] && (s>>k)&1 == 1 {
                        cnt++
                    }
                }
                if cnt%2!= p[j] {
                    ok = false
                    break
                }
            }
            if ok {
                ans += 1 << (len(v) - i)
            }
        }
    }
    fmt.Println(ans)
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

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoNums(reader)
    li := make([][]int, m)
    for i := 0; i < m; i++ {
        li[i] = readNNums(reader, n-1)
    }
    p := readNNums(reader, n)
    q := make(map[int]bool)
    for i := 1; i <= n; i++ {
        q[i] = true
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n-1; j++ {
            if q[li[i][j]] {
                delete(q, li[i][j])
            }
        }
    }
    v := make([]int, 0, len(q))
    for k := range q {
        v = append(v, k)
    }
    ans := 0
    for i := 0; i <= len(q); i++ {
        for s := 0; s < (1 << len(v)); s++ {
            ok := true
            for j := 0; j < m; j++ {
                cnt := 0
                for k := 0; k < n-1; k++ {
                    if q[li[j][k]] && (s>>k)&1 == 1 {
                        cnt++
                    }
                }
                if cnt%2!= p[j] {
                    ok = false
                    break
                }
            }
            if ok {
                ans += 1 << (len(v) - i)
            }
        }
    }
    fmt.Println(ans)
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

