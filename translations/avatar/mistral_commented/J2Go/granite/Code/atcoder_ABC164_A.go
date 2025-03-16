
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var (
        sheep int
        wolve int
        line  string
        lines []string
    )

    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        line = scanner.Text()
        lines = append(lines, line)
    }

    if err := scanner.Err(); err!= nil {
        fmt.Println(err)
    }

    numlist := strings.Split(lines[0], " ")
    sheep, _ = strconv.Atoi(numlist[0])
    wolve, _ = strconv.Atoi(numlist[1])

    if wolve >= sheep {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

