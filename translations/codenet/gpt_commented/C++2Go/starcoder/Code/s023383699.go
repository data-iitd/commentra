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
    fmt.Print("Enter an integer: ")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    x, _ := strconv.Atoi(input)
    fmt.Printf("Cube of %d is %d\n", x, x*x*x)
}

