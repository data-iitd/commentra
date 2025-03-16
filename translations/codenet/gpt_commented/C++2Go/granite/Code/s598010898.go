
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    reader := bufio.NewReader(os.Stdin)
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))
    aStr := strings.Split(strings.TrimSpace(reader.ReadLineString()), " ")
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(aStr[i])
    }
    bStr := strings.Split(strings.TrimSpace(reader.ReadLineString()), " ")
    b := make([]int, n)
    for i := 0; i < n; i++ {
        b[i], _ = strconv.Atoi(bStr[i])
    }
    sum := 0
    for i := 0; i < n; i++ {
        if a[i] - b[i] > 0 {
            sum += a[i] - b[i]
        }
    }
    fmt.Println(sum)
}

