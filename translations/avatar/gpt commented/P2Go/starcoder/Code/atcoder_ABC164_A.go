package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read two integers from input: S (the strength) and W (the weight)
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter S: ")
    S, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Print("Enter W: ")
    W, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

