
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    str, _ := reader.ReadString('\n')
    k, _ := strconv.ParseInt(reader.ReadString('\n')[0:len(reader.ReadString('\n'))-1], 10, 64)

    c := []rune(str)
    n := len(c)

    for i := int64(0); i < k; i++ {
        if string(c[i]) == "1" {
            if i == k-1 {
                fmt.Println(1)
                return
            }
        } else {
            fmt.Println(string(c[i]))
            return
        }
    }
}

