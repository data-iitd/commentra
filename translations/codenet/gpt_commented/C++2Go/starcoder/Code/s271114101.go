package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, b, c int
    var input string
    var input_array []string

    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter three integers: ")
    input, _ = reader.ReadString('\n')
    input_array = strings.Split(input, " ")
    a, _ = strconv.Atoi(input_array[0])
    b, _ = strconv.Atoi(input_array[1])
    c, _ = strconv.Atoi(input_array[2])

    if a+b == c || b+c == a || a+c == b {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

