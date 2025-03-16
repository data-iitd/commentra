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
    fmt.Print("Enter four integers: ")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    a, _ := strconv.Atoi(input[:len(input)-1])
    b, _ := strconv.Atoi(input[len(input)-1:])
    fmt.Print("Enter four integers: ")
    input, _ = reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    c, _ := strconv.Atoi(input[:len(input)-1])
    d, _ := strconv.Atoi(input[len(input)-1:])
    fmt.Println((a - c) * (b - d))
}

