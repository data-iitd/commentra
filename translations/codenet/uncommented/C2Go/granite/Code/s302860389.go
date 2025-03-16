
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
    inputNumbers, _ := reader.ReadString('\n')
    inputNumbers = strings.TrimSpace(inputNumbers)

    temp := make([]string, 2)
    temp[1] = ""

    temp[0] = string(inputNumbers[0])
    a, _ := strconv.Atoi(temp[0])
    temp[0] = string(inputNumbers[1])
    b, _ := strconv.Atoi(temp[0])
    temp[0] = string(inputNumbers[2])
    c, _ := strconv.Atoi(temp[0])
    temp[0] = string(inputNumbers[3])
    d, _ := strconv.Atoi(temp[0])

    for i := 0; i < 2; i++ {
        for j := 0; j < 2; j++ {
            for k := 0; k < 2; k++ {
                if i == 0 {
                    sum := a + b
                    symbols := "+"
                } else {
                    sum := a - b
                    symbols := "-"
                }

                if j == 0 {
                    sum = sum + c
                    symbols = symbols + "+"
                } else {
                    sum = sum - c
                    symbols = symbols + "-"
                }

                if k == 0 {
                    sum = sum + d
                    symbols = symbols + "+"
                } else {
                    sum = sum - d
                    symbols = symbols + "-"
                }

                if sum == 7 {
                    fmt.Printf("%d%s%d%s%d%s%d=7\n", a, symbols, b, symbols, c, symbols, d)
                    return
                }
            }
        }
    }
}

