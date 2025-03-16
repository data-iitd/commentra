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
    fmt.Println("Enter the number of people:")
    input, _ := reader.ReadString('\n')
    N, _ := strconv.Atoi(strings.TrimSpace(input))
    fmt.Println("Enter the number of people to be left out:")
    input, _ = reader.ReadString('\n')
    A, _ := strconv.Atoi(strings.TrimSpace(input))
    fmt.Println(N%500 <= A)
}

