
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    x, _ := strconv.ParseInt(read(reader), 10, 64)
    sum := int64(100)
    i := 0
    for sum < x {
        sum += sum / 100
        i++
    }
    fmt.Println(i)
}

func read(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err!= nil {
        panic(err)
    }
    return string(str)
}

