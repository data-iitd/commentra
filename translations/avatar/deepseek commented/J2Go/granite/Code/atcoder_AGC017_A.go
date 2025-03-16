

package main

import (
    "bufio"
    "fmt"
    "math/big"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, p int
    fmt.Fscanf(reader, "%d %d\n", &n, &p)
    var k0, k1 int
    for i := 0; i < n; i++ {
        var x int
        fmt.Fscanf(reader, "%d\n", &x)
        if x%2 == 1 {
            k1++
        } else {
            k0++
        }
    }
    ans := big.NewInt(1)
    for i := 0; i < k0; i++ {
        ans.Mul(ans, big.NewInt(2))
    }
    if p == 0 {
        add := big.NewInt(0)
        for i := 0; i <= k1; i += 2 {
            add.Add(add, combination(k1, i))
        }
        ans.Mul(ans, add)
    } else {
        add := big.NewInt(0)
        for i := 1; i <= k1; i += 2 {
            add.Add(add, combination(k1, i))
        }
        ans.Mul(ans, add)
    }
    fmt.Println(ans)
}

func combination(n, k int) *big.Int {
    if k > n {
        return big.NewInt(0)
    }
    if k > n-k {
        k = n - k
    }
    res := big.NewInt(1)
    for i := 0; i < k; i++ {
        res.Mul(res, big.NewInt(int64(n-i)))
        res.Div(res, big.NewInt(int64(i+1)))
    }
    return res
}

// END-OF-CODE