
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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    a := readLine(reader)
    aSplit := strings.Split(a, " ")
    aValues := make([]int, n)
    for i := 0; i < n; i++ {
        aValues[i], _ = strconv.Atoi(aSplit[i])
    }
    b := make([][]int, n)
    for i := 0; i < n; i++ {
        b[i] = make([]int, n)
    }
    for i := 0; i < n; i++ {
        m := aValues[i]
        for j := 0; j < n; j++ {
            k := i - j
            if k < 0 {
                k += n
            }
            m = int(Min(int64(m), int64(aValues[k])))
            b[j][i] = m
        }
    }
    m := int64(1000000000)
    for i, j := range b {
        m = Min(m, int64(sum(j))+int64(x)*int64(i))
    }
    fmt.Println(m)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

func Min(x, y int64) int64 {
    if x < y {
        return x
    }
    return y
}

func sum(a []int) int {
    s := 0
    for _, v := range a {
        s += v
    }
    return s
}

