

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
    fmt.Println("Enter a, b, and t:")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    parts := strings.Split(text, " ")
    a, _ := strconv.Atoi(parts[0])
    b, _ := strconv.Atoi(parts[1])
    t, _ := strconv.Atoi(parts[2])
    cookie := 0
    time := a
    for time <= t+0.5 {
        cookie += b
        time += a
    }
    fmt.Println(cookie)
}

