

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
    inputSlice := strings.Split(input, " ")
    h, _ := strconv.Atoi(inputSlice[0])
    a, _ := strconv.Atoi(inputSlice[1])
    num := 0
    for i := 1; h > 0; i++ {
        h = h - a
        num++
    }
    fmt.Println(num)
}

