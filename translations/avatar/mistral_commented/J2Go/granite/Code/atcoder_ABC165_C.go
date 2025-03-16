

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    a, b, c, d []int
    n, m, q   int
    ans         int64 = -100000000000000000
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var err error
    n, err = strconv.Atoi(scanner.Text())
    if err!= nil {
        panic(err)
    }

    scanner.Scan()
    m, err = strconv.Atoi(scanner.Text())
    if err!= nil {
        panic(err)
    }

    scanner.Scan()
    q, err = strconv.Atoi(scanner.Text())
    if err!= nil {
        panic(err)
    }

    a = make([]int, q)
    b = make([]int, q)
    c = make([]int, q)
    d = make([]int, q)
    for i := 0; i < q; i++ {
        scanner.Scan()
        a[i], err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
        a[i]--

        scanner.Scan()
        b[i], err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
        b[i]--

        scanner.Scan()
        c[i], err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }

        scanner.Scan()
        d[i], err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    dfs(make([]int, 0))
    fmt.Println(ans)
}

func dfs(list []int) {
    if len(list) == n {
        score := int64(0)
        for i := 0; i < q; i++ {
            if list[b[i]]-list[a[i]] == c[i] {
                score += int64(d[i])
            }
        }
        if ans < score {
            ans = score
        }
        return
    }
    if len(list)!= 0 {
        for num := list[len(list)-1]; num <= m; num++ {
            list = append(list, num)
            dfs(list)
            list = list[:len(list)-1]
        }
    } else {
        for num := 1; num <= m; num++ {
            list = append(list, num)
            dfs(list)
            list = list[:len(list)-1]
        }
    }
}

// 