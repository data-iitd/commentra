
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func solve(H int, W int, A int, B int) {
    answer := make([][]string, H)
    for i := 0; i < H; i++ {
        answer[i] = make([]string, W)
        for j := 0; j < W; j++ {
            if i < B {
                if j < A {
                    answer[i][j] = "0"
                } else {
                    answer[i][j] = "1"
                }
            } else {
                if j < A {
                    answer[i][j] = "1"
                } else {
                    answer[i][j] = "0"
                }
            }
        }
    }
    for i := 0; i < H; i++ {
        fmt.Println(strings.Join(answer[i], ""))
    }
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var H int
    scanner.Scan()
    H, _ = strconv.Atoi(scanner.Text())
    var W int
    scanner.Scan()
    W, _ = strconv.Atoi(scanner.Text())
    var A int
    scanner.Scan()
    A, _ = strconv.Atoi(scanner.Text())
    var B int
    scanner.Scan()
    B, _ = strconv.Atoi(scanner.Text())
    solve(H, W, A, B)
}

