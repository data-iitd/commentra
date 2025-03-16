
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
    r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    D, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    for i := 2; i < 12; i++ {
        fmt.Println(int((math.Pow(float64(r), float64(i-1))) * (float64(x) + float64(D)/(1-float64(r))))) - int(float64(D)/(1-float64(r))))
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}
