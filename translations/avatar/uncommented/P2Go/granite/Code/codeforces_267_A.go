
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func substract(a, b int) int {
    if a > b {
        total := 0
        for a > 0 && b > 0 {
            total += a / b
            a = a % b
            if a > 0 {
                total += b / a
                b = b % a
            }
        }
        return total
    }
    if a < b {
        total := 0
        for a > 0 && b > 0 {
            total += b / a
            b = b % a
            if b > 0 {
                total += a / b
                a = a % b
            }
        }
        return total
    }
    if a == b {
        return 1
    }
    return 0
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of test cases: ")
    n, _ := strconv.Atoi(reader.ReadLine())
    for i := 0; i < n; i++ {
        fmt.Print("Enter the values for a and b: ")
        input := reader.ReadLine()
        values := strings.Split(string(input), " ")
        a, _ := strconv.Atoi(values[0])
        b, _ := strconv.Atoi(values[1])
        result := substract(a, b)
        fmt.Println("Result:", result)
    }
}

