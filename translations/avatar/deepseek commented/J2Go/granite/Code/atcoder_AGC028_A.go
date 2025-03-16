
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
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))
    mStr, _ := reader.ReadString('\n')
    m, _ := strconv.Atoi(strings.TrimSpace(mStr))
    s, _ := reader.ReadString('\n')
    t, _ := reader.ReadString('\n')
    gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m)))
    for k := 0; k < gcd.Int64(); k++ {
        if s[k*n/gcd]!= t[k*m/gcd] {
            fmt.Println(-1)
            return
        }
    }
    result := big.NewInt(0).Mul(big.NewInt(int64(n)), big.NewInt(int64(m)))
    result.Div(result, gcd)
    fmt.Println(result)
}

