
package main

import (
    "bufio"
    "bytes"
    "container/heap"
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
    inf = bufio.NewReader(bytes.NewReader([]byte("100000000000000000")))
)

func main() {
    s := readString()
    pp := 0
    na := 0
    for i, c := range []rune(s) {
        cc := int(c-'0') + na
        na = 0
        if cc <= 4 {
            pp += cc
        } else {
            na = 1
            if i == len(s)-1 {
                pp += 1
            }
            pp += 10 - cc
        }
    }
    fmt.Println(pp)
}

func read() (x int) {
    buf := make([]byte, 10)
    _, _ = inf.Read(buf)
    x, _ = strconv.Atoi(string(buf))
    return x
}

func readString() string {
    s, _ := inf.ReadString('\n')
    return s[:len(s)-1]
}

func readBytes() []byte {
    buf := make([]byte, 10)
    _, _ = inf.Read(buf)
    return buf
}

func readInt64() int64 {
    buf := make([]byte, 10)
    _, _ = inf.Read(buf)
    i, _ := strconv.ParseInt(string(buf), 10, 64)
    return i
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}

func pow(a, b int) int {
    return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
    return int(math.Abs(float64(a)))
}

func mod(a, b int) int {
    return a - b*int(math.Floor(float64(a)/float64(b)))
}

func lcm(a, b int) int {
    return a * b / gcd(a, b)
}

func gcd(a, b int) int {
    if a == 0 || b == 0 {
        return max(a, b)
    }
    var sa, sb int
    for a%2 == 0 {
        sa++
        a /= 2
    }
    for b%2 == 0 {
        sb++
        b /= 2
    }
    if a == b {
        return a << max(sa, sb)
    }
    for a%b!= 0 {
        a, b = b, a%b
    }
    return b << max(sa, sb)
}

func isPrime(x int) bool {
    if x == 2 {
        return true
    }
    if x < 2 || x%2 == 0 {
        return false
    }
    for i := 3; i*i <= x; i += 2 {
        if x%i == 0 {
            return false
        }
    }
    return true
}

func numDigits(x int) int {
    return bits.Len64(uint64(x))
}

func bitCount(x int) int {
    return bits.OnesCount64(uint64(x))
}

func sum(a []int) int {
    ret := 0
    for _, a := range a {
        ret += a
    }
    return ret
}

func product(a []int) int {
    ret := 1
    for _, a := range a {
        ret *= a
    }
    return ret
}

func minSlice(a []int) int {
    ret := math.MaxInt32
    for _, a := range a {
        if a < ret {
            ret = a
        }
    }
    return ret
}

func maxSlice(a []int) int {
    ret := math.MinInt32
    for _, a := range a {
        if a > ret {
            ret = a
        }
    }
    return ret
}

func p(a...interface{}) {
    fmt.Println(a...)
}

func cf(format string, a...interface{}) {
    fmt.Printf(format, a...)
    fmt.Println()
}

