
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    K, _ := strconv.Atoi(read())
    if K%2 == 0 || K%5 == 0 {
        fmt.Println(-1)
        return
    }
    if K%7 == 0 {
        K /= 7
    }
    K *= 9
    ans := 1
    remainder := 10 % K
    for remainder!= 1 {
        ans++
        remainder = remainder*10 % K
    }
    fmt.Println(ans)
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return strings.TrimSpace(string(buf))
}

func readInt() int {
    i, err := strconv.Atoi(read())
    checkError(err)
    return i
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func write(str string) {
    fmt.Fprintln(out, str)
}

func writeInt(i int) {
    fmt.Fprintln(out, i)
}

func writeIntArray(arr []int) {
    for _, num := range arr {
        fmt.Fprint(out, num, " ")
    }
    fmt.Fprintln(out)
}

func main() {
    K := readInt()
    if K%2 == 0 || K%5 == 0 {
        write("-1")
        return
    }
    if K%7 == 0 {
        K /= 7
    }
    K *= 9
    ans := 1
    remainder := 10 % K
    for remainder!= 1 {
        ans++
        remainder = remainder*10 % K
    }
    writeInt(ans)
}

