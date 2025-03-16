
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
        str, _ := reader.ReadString('\n')
        if str == "0\n" {
            break
        }
        sum := 0
        for _, c := range str {
            num, _ := strconv.Atoi(string(c))
            sum += num
        }
        fmt.Println(sum)
    }
}
