

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
    fmt.Print("Enter the first number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.ParseInt(strings.TrimSpace(text), 10, 64)

    var digits []int
    for number > 0 {
        digit := int(number % 10)
        digits = append(digits, digit)
        number /= 10
    }

    var newNumber int64
    for i, digit := range digits {
        power := len(digits) - i - 1
        newNumber += int64(digit) * int64(pow(10, power))
    }

    fmt.Println(newNumber)
}

func pow(x, n int) int {
    result := 1
    for i := 0; i < n; i++ {
        result *= x
    }
    return result
}

Translate the above Go code to C++ and end with comment "