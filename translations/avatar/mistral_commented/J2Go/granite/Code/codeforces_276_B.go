

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)

    charCount := make(map[string]int)

    for _, ch := range str {
        charCount[string(ch)]++
    }

    oddCount := 0

    for _, count := range charCount {
        if count%2!= 0 {
            oddCount++
        }
    }

    if oddCount <= 1 || oddCount%2!= 0 {
        fmt.Fprintln(writer, "First")
    } else {
        fmt.Fprintln(writer, "Second")
    }

    writer.Flush()
}

