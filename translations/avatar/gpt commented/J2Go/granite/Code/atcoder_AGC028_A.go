
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
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var n int
    scanner.Scan()
    n, _ = strconv.Atoi(scanner.Text())
    var m int
    scanner.Scan()
    m, _ = strconv.Atoi(scanner.Text())
    s := scanner.Text()
    t := scanner.Text()
    gcd := new(big.Int).SetInt64(int64(n)).GCD(nil, nil, new(big.Int).SetInt64(int64(m)))
    for k := 0; k < gcd.Int64(); k++ {
        if s[k*n/gcd.Int64()]!= t[k*m/gcd.Int64()] {
            fmt.Println(-1)
            return
        }
    }
    fmt.Println(new(big.Int).SetInt64(int64(n)).Mul(new(big.Int).SetInt64(int64(m)), new(big.Int).SetInt64(int64(gcd)).Inv(new(big.Int).SetInt64(int64(gcd)))))
}

