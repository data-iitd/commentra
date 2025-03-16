package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    S, _ := reader.ReadString('\n')
    S = strings.TrimSpace(S)

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    S = Reverse(S)
    for i := 0; i < 4; i++ {
        divide[i] = Reverse(divide[i])
    }

    // 端から切っていく
    can := true
    for i := 0; i < len(S); {
        can2 := false
        for j := 0; j < 4; j++ {
            d := divide[j]
            if S[i:i+len(d)] == d {
                can2 = true
                i += len(d)
            }
        }
        if!can2 {
            can = false
            break
        }
    }

    if can {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func Reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

