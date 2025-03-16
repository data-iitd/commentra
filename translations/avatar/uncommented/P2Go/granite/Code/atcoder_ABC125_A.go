
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
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    inputs := strings.Split(input, " ")
    a, _ := strconv.Atoi(inputs[0])
    b, _ := strconv.Atoi(inputs[1])
    t, _ := strconv.Atoi(inputs[2])
    cookie := 0
    time := a
    for time <= t+0.5 {
        cookie += b
        time += a
    }
    fmt.Println(cookie)
}
