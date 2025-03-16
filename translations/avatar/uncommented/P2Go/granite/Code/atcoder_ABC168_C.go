
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    h, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))
    if C > 180 {
        C = 360 - C
    }
    cosC := math.Cos(math.Pi * C / 180)
    fmt.Println(math.Sqrt(float64(a*a+b*b-2*a*b*cosC)))
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

