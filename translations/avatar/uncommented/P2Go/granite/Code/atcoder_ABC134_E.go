
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N := readNum(reader)
    ans := make([][]int, 0, N)
    for i := 0; i < N; i++ {
        A := readNum(reader)
        idx := search(ans, A)
        if idx == len(ans) {
            ans = append(ans, []int{A})
        } else {
            ans[idx] = append(ans[idx], A)
        }
    }
    fmt.Println(len(ans))
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

func search(ans [][]int, key int) int {
    bad, good := -1, len(ans)
    for good-bad > 1 {
        mid := (bad + good) / 2
        if ans[mid][len(ans[mid])-1] < key {
            good = mid
        } else {
            bad = mid
        }
    }
    return good
}
