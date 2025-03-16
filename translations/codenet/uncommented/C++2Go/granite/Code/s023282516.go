
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

var divide = []string{"dream", "dreamer", "erase", "eraser"}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var S string
    scanner.Scan()
    S = scanner.Text()

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    S = reverse(S)
    for i := 0; i < 4; i++ {
        divide[i] = reverse(divide[i])
    }

    // 端から切っていく
    can := true
    for i := 0; i < len(S); {
        can2 := false // 4 個の文字列たちどれかで divide できるか
        for j := 0; j < 4; j++ {
            d := divide[j]
            if strings.EqualFold(S[i:i+len(d)], d) { // d で divide できるか
                can2 = true
                i += len(d) // divide できたら i を進める
            }
        }
        if!can2 { // divide できなかったら
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

func reverse(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

