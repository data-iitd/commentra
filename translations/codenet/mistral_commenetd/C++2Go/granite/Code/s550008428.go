

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
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(strings.TrimSpace(text))

    set := make(map[int]bool)
    set[number] = true

    d := 2
    for {
        if number%2 == 0 {
            number /= 2
        } else {
            number = 3*number + 1
        }
        if set[number] {
            fmt.Println(d)
            break
        }
        set[number] = true
        d++
    }

    fmt.Println("