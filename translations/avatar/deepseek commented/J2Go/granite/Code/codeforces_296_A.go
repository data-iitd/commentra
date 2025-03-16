
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    reader *bufio.Reader
    writer *bufio.Writer
)

func check(e error) {
    if e!= nil {
        panic(e)
    }
}

func init() {
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
}

func readString() string {
    string, _ := reader.ReadString('\n')
    return strings.TrimSpace(string)
}

func readInt() int {
    result, _ := strconv.Atoi(readString())
    return result
}

func readInt64() int64 {
    result, _ := strconv.ParseInt(readString(), 10, 64)
    return result
}

func readFloat64() float64 {
    result, _ := strconv.ParseFloat(readString(), 64)
    return result
}

func readLine() {
    _, _ = reader.ReadString('\n')
}

func main() {
    n := readInt()
    a := make([]int, 1001)
    for i := 0; i < n; i++ {
        a[readInt()]++
    }
    maxCount := 0
    for i := 1; i < 1001; i++ {
        if a[i] > maxCount {
            maxCount = a[i]
        }
    }
    if n%2 == 0 {
        if maxCount <= n/2 {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    } else {
        if maxCount <= n/2+1 {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
    writer.Flush()
}

// 