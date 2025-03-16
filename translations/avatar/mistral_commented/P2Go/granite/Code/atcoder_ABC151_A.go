
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var debug bool = false

func log(text string) {
    if debug {
        fmt.Println(text)
    }
}

func parse_input(lines_as_string string) []string {
    debug = true
    lines := strings.Split(lines_as_string, "\n")
    return lines[1 : len(lines)-1]
}

func solve(c string) string {
    a := "abcdefghijklmnopqrstuvwxyz"
    i, _ := strconv.Atoi(string(a[0]))
    for _, v := range a {
        if string(v) == c {
            i++
            break
        }
    }
    return string(a[i])
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    result := solve(scanner.Text())
    fmt.Println(result)
}

// END-OF-CODE