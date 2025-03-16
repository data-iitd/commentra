package main

import (
    "fmt"
    "os"
    "bufio"
    "strings"
)

func main() {
    var B, OUT string
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a character: ")
    B, _ = reader.ReadString('\n')
    B = strings.TrimSpace(B)
    if B == "A" {
        OUT = "T"
    } else if B == "T" {
        OUT = "A"
    } else if B == "C" {
        OUT = "G"
    } else {
        OUT = "C"
    }
    fmt.Println(OUT)
}

