
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
var n, m int
fmt.Fscanf(scanner, "%d %d\n", &n, &m)
var s, t string
fmt.Fscanf(scanner, "%s %s\n", &s, &t)
gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m)))
var k int64
for k = 0; k < gcd.Int64(); k++ {
if s[k*n/gcd.Int64()]!= t[k*m/gcd.Int64()] {
break
}
}
result := big.NewInt(0).Mul(big.NewInt(int64(n)), big.NewInt(int64(m)))
result.Div(result, gcd)
fmt.Println(result)
}


