
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
    acCount := 0
    waCount := 0
    tleCount := 0
    reCount := 0
    for i := 0; i < n; i++ {
        result := readLine(reader)
        switch result {
        case "AC":
            acCount++
        case "WA":
            waCount++
        case "TLE":
            tleCount++
        case "RE":
            reCount++
        }
    }
    fmt.Printf("AC x %d\n", acCount)
    fmt.Printf("WA x %d\n", waCount)
    fmt.Printf("TLE x %d\n", tleCount)
    fmt.Printf("RE x %d\n", reCount)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

