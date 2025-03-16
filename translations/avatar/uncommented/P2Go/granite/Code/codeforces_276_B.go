
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    s := strings.Split(text, "")
    dt := make(map[string]int)
    for _, i := range s {
        dt[i]++
    }
    cnt := 0
    for _, value := range dt {
        if value%2!= 0 && cnt < 1 {
            cnt++
        } else if value%2!= 0 && cnt >= 1 {
            fmt.Println("Second")
            return
        }
    }
    fmt.Println("First")
}
