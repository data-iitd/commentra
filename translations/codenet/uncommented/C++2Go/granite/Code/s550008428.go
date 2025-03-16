
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
    num, _ := strconv.Atoi(strings.TrimSpace(text))

    set := make(map[int]bool)
    set[num] = true

    d := 2
    for {
        if num%2 == 0 {
            x := num / 2
            if set[x] {
                fmt.Println(d)
                return
            }
            set[x] = true
        } else {
            x := 3*num + 1
            if set[x] {
                fmt.Println(d)
                return
            }
            set[x] = true
        }
        num = x
        d++
    }

    fmt.Println(d)
}

