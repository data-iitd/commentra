

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the value of N
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)

    // Initialize min to 0 and find the minimum of the first five inputs
    min := int64(0)
    for i := 0; i < 5; i++ {
        if i == 0 {
            min, _ = strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        } else {
            temp, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
            if temp < min {
                min = temp
            }
        }
    }

    // Calculate the result and print it
    fmt.Println(int64(int(N/min)+4))
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

// Overloaded print methods to handle different data types
func p(ans string) {
    fmt.Println(ans)
}

func p(ans int) {
    fmt.Println(ans)
}

func p() {
    fmt.Println()
}

func p(ans int64) {
    fmt.Println(ans)
}

func p(ans float64) {
    fmt.Println(ans)
}

// End of code