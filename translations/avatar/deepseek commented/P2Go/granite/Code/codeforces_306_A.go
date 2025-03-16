

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
    fmt.Println("Enter two integers n and m:")
    text, _ := reader.ReadString('\n')
    numbers := strings.Split(text, " ")
    n, _ := strconv.Atoi(numbers[0])
    m, _ := strconv.Atoi(numbers[1])

    q := n / m
    r := n % m

    a := make([]int, m)
    for i := 0; i < m; i++ {
        a[i] = q
    }

    for i := 0; i < r; i++ {
        a[i]++
    }

    for i := 0; i < m; i++ {
        fmt.Printf("%d ", a[i])
    }

    fmt.Println()
}

