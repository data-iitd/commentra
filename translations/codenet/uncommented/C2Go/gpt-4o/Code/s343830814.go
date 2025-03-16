package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    buf, _ := reader.ReadString('\n')
    len := len(buf)
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

// <END-OF-CODE>
