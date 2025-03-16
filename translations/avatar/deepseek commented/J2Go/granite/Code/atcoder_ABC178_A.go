

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    x, _ := strconv.Atoi(reader.ReadLine())
    bool := x == 1
    result := 0
    if!bool {
        result = 1
    }
    fmt.Println(result)
}

