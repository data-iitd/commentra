

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
    n, _ := strconv.Atoi(strings.TrimSpace(text))
    a := []int{10, 100, 1000, 10000, 100000}
    var new int
    for _, digit := range []byte(strconv.Itoa(n)) {
        new += int(digit - '0')
    }
    if contains(a, n) {
        fmt.Println(10)
    } else {
        fmt.Println(new)
    }
}

func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

