
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
    var n, t int
    var s []int
    var current_cell int
    fmt.Fscanf(reader, "%d %d\n", &n, &t)
    s_temp := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    for i := 0; i < int(n); i++ {
        temp, err := strconv.Atoi(s_temp[i])
        checkError(err)
        s = append(s, temp)
    }
    current_cell = 0
    for current_cell <= t {
        current_cell += s[current_cell-1]
        if current_cell == t {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

