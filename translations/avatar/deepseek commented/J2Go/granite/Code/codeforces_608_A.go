
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
    s, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    max := 0
    for i := 0; i < n; i++ {
        aTemp := strings.Split(readLine(reader), " ")
        a, _ := strconv.Atoi(aTemp[0])
        b, _ := strconv.Atoi(aTemp[1])
        if max < a+b {
            max = a + b
        }
    }
    fmt.Println(int(Max(int64(max), int64(s))))
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func Max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

