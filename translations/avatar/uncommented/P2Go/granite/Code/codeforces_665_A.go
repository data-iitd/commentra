
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
    a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    at, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    bt, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    t1, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    t2, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    st := t2 + (t1-5)*60
    fin := st + at
    now := 0
    ans := 0
    for now < fin && now < 1140 {
        if now+bt > st {
            ans += 1
        }
        now += b
    }
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

