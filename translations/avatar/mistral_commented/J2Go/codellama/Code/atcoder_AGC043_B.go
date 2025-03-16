
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Declaring a private method to calculate the XOR operation on a given string with a specific character
func cal(s string, c byte) int {
    n := len(s)
    m := n - 1
    ans := 0

    for i := 0; i < n; i++ {
        if s[i] == c && (m&i) == i {
            ans ^= 1
        }
    }

    return ans
}

// Declaring a private method to read input and process it
func solve() {
    var n int
    fmt.Scan(&n)

    for testCase := 1; testCase <= n; testCase++ {
        var num int
        fmt.Scan(&num)

        s := make([]byte, num)
        fmt.Scan(&s)

        sb := strings.Builder{}

        for i := 1; i < num; i++ {
            sb.WriteString(strconv.Itoa(int(math.Abs(float64(s[i] - s[i-1])))))
        }

        if num == 2 {
            fmt.Println(s[0])
            continue
        }

        s = sb.String()

        if strings.Contains(s, "1") {
            fmt.Println(cal(s, '1'))
        } else {
            fmt.Println(cal(s, '2') * 2)
        }
    }
}

// Declaring static variables for input/output operations
var out *bufio.Writer
var sc *bufio.Scanner

// Declaring a static class to read input
type MyScanner struct {
    br   *bufio.Reader
    st   *strings.Builder
}

func (ms *MyScanner) next() string {
    for ms.st == nil || !ms.st.Scan() {
        ms.st = &strings.Builder{}
        ms.br.WriteTo(ms.st)
    }
    return ms.st.String()
}

func (ms *MyScanner) nextInt() int {
    return int(ms.nextInt64())
}

func (ms *MyScanner) nextInt64() int64 {
    return int64(ms.nextInt32())
}

func (ms *MyScanner) nextInt32() int32 {
    return int32(ms.nextInt16())
}

func (ms *MyScanner) nextInt16() int16 {
    return int16(ms.nextInt8())
}

func (ms *MyScanner) nextInt8() int8 {
    return int8(ms.nextUint64())
}

func (ms *MyScanner) nextUint64() uint64 {
    return uint64(ms.nextUint32())
}

func (ms *MyScanner) nextUint32() uint32 {
    return uint32(ms.nextUint16())
}

func (ms *MyScanner) nextUint16() uint16 {
    return uint16(ms.nextUint8())
}

func (ms *MyScanner) nextUint8() uint8 {
    return uint8(ms.nextFloat64())
}

func (ms *MyScanner) nextFloat64() float64 {
    return float64(ms.nextFloat32())
}

func (ms *MyScanner) nextFloat32() float32 {
    return float32(ms.nextFloat16())
}

func (ms *MyScanner) nextFloat16() float16.Float16 {
    return float16.Parse(ms.next())
}

// Declaring the main method to start the program
func main() {
    out = bufio.NewWriter(os.Stdout)
    sc = bufio.NewScanner(os.Stdin)
    solve()
    out.Flush()
}

