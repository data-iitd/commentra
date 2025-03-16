
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
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(strings.TrimSpace(text))
    a := []int{10, 100, 1000, 10000, 100000}
    new := 0
    for _, value := range strings.Split(text, "") {
        new += int(value[0]) - 48
    }
    if contains(a, number) {
        fmt.Println(10)
    } else {
        fmt.Println(new)
    }
}

func contains(a []int, x int) bool {
    for _, n := range a {
        if x == n {
            return true
        }
    }
    return false
}

