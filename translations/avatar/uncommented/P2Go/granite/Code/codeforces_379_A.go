
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
    candeleIntere, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    s := 0
    restoSciolte := 0
    for candeleIntere > 0 || restoSciolte >= b {
        candeleIntere += restoSciolte / b
        restoSciolte %= b
        s += candeleIntere
        restoSciolte += candeleIntere % b
        candeleIntere /= b
    }
    fmt.Println(s)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

