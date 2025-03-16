

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
    fmt.Println("Enter A, B, and n:")
    text, _ := reader.ReadString('\n')
    text = strings.Replace(text, "\n", "", -1)
    parts := strings.Split(text, " ")
    A, _ := strconv.Atoi(parts[0])
    B, _ := strconv.Atoi(parts[1])
    n, _ := strconv.Atoi(parts[2])

    if A == 0 {
        if B == 0 {
            fmt.Println(1)
        } else {
            fmt.Println("No solution")
        }
        return
    }

    if B%A!= 0 {
        fmt.Println("No solution")
        return
    }

    B /= A
    neg := B < 0
    if neg && n%2 == 0 {
        fmt.Println("No solution")
        return
    }
    if neg {
        B = -B
    }

    for x := 0; x <= B; x++ {
        if int(float64(x)*float64(x)*float64(n)) == B {
            if neg {
                fmt.Println(-x)
            } else {
                fmt.Println(x)
            }
            return
        }
    }

    fmt.Println("No solution")
}
