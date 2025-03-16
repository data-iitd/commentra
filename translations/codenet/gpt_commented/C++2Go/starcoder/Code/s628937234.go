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
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)
    t := s[0:1]
    t += strconv.Itoa(len(s) - 2)
    t += s[len(s)-1:]
    fmt.Println(t)
}

