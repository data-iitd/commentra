
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    N, K int
    S     string
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    input := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    N, _ = strconv.Atoi(input[0])
    K, _ = strconv.Atoi(input[1])
    S = readLine(reader)
    aaaa := false
    if K >= 15 {
        aaaa = true
    } else if 1<<uint(K) >= N {
        aaaa = true
    }
    if aaaa {
        fmt.Println(strings.Repeat(string(S[0]), N))
        return
    }
    get_last_dict(S)
    if K == 1 {
        fmt.Println(S)
    } else {
        count := 0
        for _, c := range S {
            if c == S[0] {
                count++
            } else {
                break
            }
        }
        if count*(1<<(K-1)) >= N {
            fmt.Println(strings.Repeat(string(S[0]), N))
        } else {
            S = strings.Repeat(string(S[0]), count*(1<<(K-1))-1) + S
            fmt.Println(S[:N])
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

func get_last_dict(s_str string) string {
    U := s_str + reverse(s_str)
    c := s_str[0]
    p := strings.IndexByte(U, c)
    minindex := p
    p++
    for p <= N {
        if U[p] == c {
            if check_normal_dict(U, minindex, p) {
                minindex = p
            }
        }
        p++
    }
    return U[minindex : minindex+N]
}

func check_normal_dict(u string, pointer1, pointer2 int) bool {
    for i := 0; i < N; i++ {
        if u[pointer1+i] > u[pointer2+i] {
            return true
        } else if u[pointer1+i] < u[pointer2+i] {
            return false
        }
    }
    return false
}

func reverse(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
