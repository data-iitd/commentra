
package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)

    var N int
    scanner.Scan()
    N, _ = strconv.Atoi(scanner.Text())

    var M int64
    scanner.Scan()
    M, _ = strconv.ParseInt(scanner.Text(), 10, 64)

    H := make([]int64, N)
    ans := make([]bool, N)

    for i := 0; i < N; i++ {
        scanner.Scan()
        H[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
        ans[i] = true
    }

    for query := 0; query < int(M); query++ {
        var temp1 int
        scanner.Scan()
        temp1, _ = strconv.Atoi(scanner.Text())

        var temp2 int
        scanner.Scan()
        temp2, _ = strconv.Atoi(scanner.Text())

        if H[temp1-1] < H[temp2-1] {
            ans[temp1-1] = false
        } else if H[temp1-1] > H[temp2-1] {
            ans[temp2-1] = false
        } else {
            ans[temp1-1] = false
            ans[temp2-1] = false
        }
    }

    ans2 := 0
    for i := 0; i < N; i++ {
        if ans[i] {
            ans2++
        }
    }

    fmt.Println(ans2)
}

