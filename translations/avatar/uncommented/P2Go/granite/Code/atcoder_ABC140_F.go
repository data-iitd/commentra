
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    N := readInt()
    S := make([]int, N)
    for i := 0; i < N; i++ {
        S[i] = readInt()
    }
    sort.Ints(S)
    flag := make([]bool, N)
    for i := 0; i < N; i++ {
        flag[i] = true
    }
    cur := make([]int, 0, N)
    cur = append(cur, S[N-1])
    flag[N-1] = false
    for i := 0; i < N; i++ {
        j := 0
        jM := len(cur)
        for k := 0; k < N; k++ {
            if flag[k] && S[k] < cur[j] {
                cur = append(cur, S[k])
                j++
                flag[k] = false
                if j == jM {
                    break
                }
            }
        }
        if j == jM {
            fmt.Fprintln(out, "No")
            break
        }
        sort.Sort(sort.Reverse(sort.IntSlice(cur)))
    }
    fmt.Fprintln(out, "Yes")
}

func readInt() int {
    i, _ := strconv.Atoi(readWord())
    return i
}

func readWord() string {
    ret := ""
    for {
        char, _, err := in.ReadRune()
        if err!= nil {
            panic(err)
        }
        if char =='' {
            break
        }
        ret += string(char)
    }
    return ret
}

func readLine() string {
    ret := ""
    for {
        char, _, err := in.ReadRune()
        if err!= nil {
            panic(err)
        }
        if char == '\n' {
            break
        }
        ret += string(char)
    }
    return ret
}

func outInt(x int) {
    fmt.Fprint(out, x)
}

func outWord(s string) {
    fmt.Fprint(out, s)
}

func outLine(s string) {
    fmt.Fprintln(out, s)
}

func outFlush() {
    out.Flush()
}

