
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
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    numbers := strings.Split(input, " ")
    n, _ := strconv.Atoi(numbers[0])
    m, _ := strconv.Atoi(numbers[1])
    if n < 1 {
        if m < 1 {
            fmt.Println(n, m)
            return
        }
        fmt.Println("Impossible")
        return
    }
    if m > n {
        min := m
        max := n + m - 1
        fmt.Println(min, max)
    }
    if m <= n {
        min := n
        max := n + m - 1
        if m == 0 {
            max = n
        }
        fmt.Println(min, max)
    }
}
