
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, m, mod int64
    fmt.Fscanf(reader, "%d %d %d\n", &n, &m, &mod)

    C := make([][]int64, n+1)
    for i := 0; i <= n; i++ {
        C[i] = make([]int64, i+1)
        C[i][0] = 1
        C[i][i] = 1
        for j := 1; j < i; j++ {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
        }
    }

    f := make([][]int64, n+2)
    for i := 0; i <= n+1; i++ {
        f[i] = make([]int64, m+1)
        f[i][0] = 1
    }
    pre := make([][]int64, n+2)
    for i := 0; i <= n+1; i++ {
        pre[i] = make([]int64, m+2)
        pre[i][m+1] = 1
    }
    for i := 1; i <= n+1; i++ {
        for j := 1; j <= m; j++ {
            for k := 1; k < i; k++ {
                f[i][j] = (f[i][j] + f[i-k][j]*pre[k][j+1]%mod*C[i-2][k-1]) % mod
            }
        }
        for j := m; j >= 0; j-- {
            pre[i][j] = (pre[i][j+1] + f[i][j]) % mod
        }
    }

    fmt.Println(f[n+1][0])
}

