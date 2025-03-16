
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
    fmt.Print("Enter the initial number: ")
    text, _ := reader.ReadString('\n')
    num, _ := strconv.Atoi(strings.TrimSpace(text))

    set := make(map[int]bool)
    set[num] = true

    step := 1
    for {
        if num%2 == 0 {
            num /= 2
        } else {
            num = 3*num + 1
        }
        if set[num] {
            fmt.Println(step)
            break
        }
        set[num] = true
        step++
    }

    fmt.Println("