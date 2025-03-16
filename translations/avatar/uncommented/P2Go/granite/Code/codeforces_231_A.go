
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
    var n int
    fmt.Fscan(reader, &n)
    c := 0
    for i := 0; i < n; i++ {
        line, _, _ := reader.ReadLine()
        parts := strings.Split(string(line), " ")
        sum := 0
        for _, part := range parts {
            num, _ := strconv.Atoi(part)
            sum += num
        }
        if sum > 1 {
            c++
        }
    }
    fmt.Println(c)
}
