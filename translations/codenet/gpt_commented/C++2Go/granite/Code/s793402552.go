
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
    fmt.Println("Enter two integers a and b:")
    aStr, _ := reader.ReadString('\n')
    bStr, _ := reader.ReadString('\n')
    a, _ := strconv.Atoi(strings.TrimSpace(aStr))
    b, _ := strconv.Atoi(strings.TrimSpace(bStr))
    bStr = strconv.Itoa(b)
    num := a * int(math.Pow(10, float64(len(bStr)))) + b
    for i := 1; i <= 100100; i++ {
        if i*i == num {
            fmt.Println("Yes")
            return
        }
    }
    fmt.Println("No")
}

