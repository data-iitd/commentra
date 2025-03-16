

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    const (
        inf = 1e15
    )

    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    number := scanner.Text()

    digits := make([]int, len(number)+1)
    for i := 0; i < len(number); i++ {
        digit, _ := strconv.Atoi(string(number[len(number)-1-i])))
        digits[i] = digit
    }

    bills := 0
    for i := 0; i <= len(number); i++ {
        if digits[i] == 10 {
            digits[i+1]++
            digits[i] = 0
        }

        if digits[i] < 5 {
            bills += digits[i]
        } else if digits[i] == 5 {
            if digits[i+1] >= 5 {
                digits[i+1]++
            }
            bills += 5
        } else {
            digits[i+1]++
            bills += 10 - digits[i]
        }
    }

    fmt.Println(bills)
}

