
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
    var n int
    var a []int
    var b []int
    var c []int
    fmt.Fscan(reader, &n)
    a_temp := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    for i := 0; i < int(n); i++ {
        aItem, err := strconv.ParseInt(a_temp[i], 10, 64)
        checkError(err)
        a = append(a, int(aItem))
    }
    b_temp := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    for i := 0; i < int(n); i++ {
        bItem, err := strconv.ParseInt(b_temp[i], 10, 64)
        checkError(err)
        b = append(b, int(bItem))
    }
    c_temp := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    for i := 0; i < int(n); i++ {
        cItem, err := strconv.ParseInt(c_temp[i], 10, 64)
        checkError(err)
        c = append(c, int(cItem))
    }
    var x int32 = 0
    var y int32 = 0
    var z int32 = 0
    for i := 0; i < int(n); i++ {
        x += int32(a[i])
    }
    for i := 0; i < int(n); i++ {
        y += int32(b[i])
    }
    for i := 0; i < int(n); i++ {
        z += int32(c[i])
    }
    fmt.Println(int32(abs(x-y)))
    fmt.Println(int32(abs(y-z)))
    fmt.Println("