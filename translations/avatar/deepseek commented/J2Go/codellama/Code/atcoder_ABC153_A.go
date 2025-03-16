
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
    input = strings.TrimSuffix(input, "\n")
    inputArray := strings.Split(input, " ")
    h, _ := strconv.Atoi(inputArray[0])
    a, _ := strconv.Atoi(inputArray[1])
    num := 0

    for h > 0 {
        h = h - a
        num++
    }

    fmt.Println(num)
}

