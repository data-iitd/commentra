
package main

import (
    "bufio"
    "bytes"
    "container/ring"
    "fmt"
    "io"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    inf = int64(1e18)
)

func main() {
    n := readInt()
    if n == 1 {
        println(0)
        return
    }
    var fac []int
    for n%2 == 0 {
        fac = append(fac, 2)
        n /= 2
    }
    for f := 3; f*f <= n; f += 2 {
        if n%f == 0 {
            fac = append(fac, f)
            n /= f
        }
    }
    if n!= 1 {
        fac = append(fac, n)
    }
    cnt := make(map[int]int)
    for _, f := range fac {
        cnt[f]++
    }
    ans := 0
    for _, c := range cnt {
        x := c
        for i := 1; x >= i; i++ {
            x -= i
            ans++
        }
    }
    println(ans)
}

func read() (x int) {
    b := make([]byte, 0)
    for {
        c, _ := in.ReadByte()
        if '0' <= c && c <= '9' {
            b = append(b, c)
        } else {
            break
        }
    }
    for _, c := range b {
        x = x*10 + int(c-'0')
    }
    return
}

func readInt() int {
    return int(read())
}

func readInt64() int64 {
    return int64(read())
}

func readStr() string {
    b := make([]byte, 0)
    for {
        c, _ := in.ReadByte()
        if c =='' || c == '\n' {
            break
        }
        b = append(b, c)
    }
    return string(b)
}

func readBytes() []byte {
    b := make([]byte, 0)
    for {
        c, _ := in.ReadByte()
        if c =='' || c == '\n' {
            break
        }
        b = append(b, c)
    }
    return b
}

func readInt64s(n int) []int64 {
    a := make([]int64, n)
    for i := 0; i < n; i++ {
        a[i] = readInt64()
    }
    return a
}

func readUint64s(n int) []uint64 {
    a := make([]uint64, n)
    for i := 0; i < n; i++ {
        a[i] = readUint64()
    }
    return a
}

func readUint64() uint64 {
    return uint64(read())
}

func readFloat64() float64 {
    return float64(read())
}

func readLine() string {
    buf := new(bytes.Buffer)
    io.Copy(buf, in)
    return buf.String()
}

func readNInt64s(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readInt64(buf []byte, x int) (int, int64) {
    i := x
    sign := 1
    if buf[i] == '-' {
        i++
        sign = -1
    }
    res := int64(0)
    for i < len(buf) && '0' <= buf[i] && buf[i] <= '9' {
        res = res*10 + int64(buf[i]-'0')
        i++
    }
    res *= int64(sign)
    return i, res
}

func readInt64s2(n int) []int64 {
    res := make([]int64, n)
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        var x int
        x, res[i] = readInt64(buf, 0)
        buf = buf[x:]
    }
    return res
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func max(a, b int) int {
    return a + b - min(a, b)
}

func pow(a, b int) int {
    res := 1
    for b > 0 {
        if b&1 == 1 {
            res *= a
        }
        a *= a
        b >>= 1
    }
    return res
}

func powMod(a, b, mod int) int {
    res := 1
    for b > 0 {
        if b&1 == 1 {
            res = int(int64(res) * int64(a) % int64(mod))
        }
        a = int(int64(a) * int64(a) % int64(mod))
        b >>= 1
    }
    return res
}

func modInverse(a, mod int) int {
    a %= mod
    if a == 0 {
        return 0
    }
    return powMod(a, mod-2, mod)
}

func modAdd(a, b, mod int) int {
    a += b
    if a >= mod {
        a -= mod
    }
    return a
}

func modSub(a, b, mod int) int {
    a -= b
    if a < 0 {
        a += mod
    }
    return a
}

func modMul(a, b, mod int) int {
    return int(int64(a) * int64(b) % int64(mod))
}

func modDiv(a, b, mod int) int {
    a *= modInverse(b, mod)
    return a % mod
}

func fact(n int) int {
    res := 1
    for i := 2; i <= n; i++ {
        res *= i
    }
    return res
}

func nCr(n, r int) int {
    return int(int64(fact(n)) * int64(modInverse(fact(r), MOD)) % int64(MOD) * int64(modInverse(fact(n-r), MOD)) % int64(MOD))
}

func nPr(n, r int) int {
    return int(int64(fact(n)) * int64(modInverse(fact(n-r), MOD)) % int64(MOD))
}

func isPrime(n int) bool {
    if n <= 1 {
        return false
    }
    for i := 2; i*i <= n; i++ {
        if n%i == 0 {
            return false
        }
    }
    return true
}

func nextPrime(n int) int {
    if n <= 1 {
        return 2
    }
    n++
    for!isPrime(n) {
        n++
    }
    return n
}

func prevPrime(n int) int {
    if n <= 2 {
        return 2
    }
    n--
    for!isPrime(n) {
        n--
    }
    return n
}

func sortInt(a []int) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] < a[j]
    })
}

func sortInt64(a []int64) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] < a[j]
    })
}

func sortIntDesc(a []int) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] > a[j]
    })
}

func sortInt64Desc(a []int64) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] > a[j]
    })
}

func sortStr(a []string) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] < a[j]
    })
}

func readNInt64s2(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s2(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s3(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s3(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s4(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s4(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s5(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s5(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s6(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s6(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s7(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s7(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s8(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = int64(x)
    }
    return res
}

func readUint64s8(n int) []uint64 {
    res := make([]uint64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = readInt64(buf, x)
        res[i] = uint64(x)
    }
    return res
}

func readNInt64s9(n int) []int64 {
    res := make([]int64, n)
    x := 0
    buf := make([]byte, 1024)
    for i := 0; i < n; i++ {
        for x < len(buf) && (buf[x] < '0' || buf[x] > '9') && buf[x]!= '-' {
            x++
        }
        x = re