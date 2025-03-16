
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
        fmt.Print("Enter a string (0 to exit): ")
        text, _ := reader.ReadString('\n')
        if text == "0\n" {
            break
        }
        sum := 0
        for _, r := range text {
            num, _ := strconv.Atoi(string(r))
            sum += num
        }
        fmt.Println(sum)
    }
}

