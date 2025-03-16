
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        a, err := strconv.Atoi(read(reader))
        if err!= nil {
            break
        }
        c, k := 0, 0
        for a > 2 {
            a--
            c++
            if c == 3 {
                k++
                c = 0
            }
        }
        fmt.Println(k)
    }
}

func read(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err!= nil {
        panic(err)
    }
    return string(str)
}

