

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
    fmt.Println("Enter two integers separated by a space:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    parts := strings.Split(input, " ")
    x, _ := strconv.Atoi(parts[0])
    y, _ := strconv.Atoi(parts[1])
    a := 0
    for x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
        if a == 1 {
            if y >= 22 {
                y -= 22
            } else if x >= 1 && y >= 12 {
                x -= 1
                y -= 12
            } else {
                x -= 2
                y -= 2
            }
        } else {
            if x >= 2 && y >= 2 {
                x -= 2
                y -= 2
            } else if x >= 1 && y >= 12 {
                x -= 1
                y -= 12
            } else {
                y -= 22
            }
        }
        a = 1 - a
    }
    if a == 1 {
        fmt.Println("Ciel")
    } else {
        fmt.Println("Hanako")
    }
}

