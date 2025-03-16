

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var a [4]int64
    for i := 0; i < 4; i++ {
        s, _ := reader.ReadString('\n')
        s = strings.TrimSpace(s)
        a[i], _ = strconv.ParseInt(s, 10, 64)
    }
    var result int64
    result = int64(int64(a[0])*a[2])
    if int64(int64(a[1])*a[3]) > result {
        result = int64(int64(a[1])*a[3])
    }
    if int64(int64(a[0])*a[3]) > result {
        result = int64(int64(a[0])*a[3])
    }
    if int64(int64(a[1])*a[2]) > result {
        result = int64(int64(a[1])*a[2])
    }
    fmt.Println(result)
}

