
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter T, S, and q:")
    T, _ := strconv.Atoi(reader.ReadLine())
    S, _ := strconv.Atoi(reader.ReadLine())
    q, _ := strconv.Atoi(reader.ReadLine())
    previous := S
    answer := 0
    for previous < T {
        answer++
        previous *= q
    }
    fmt.Println(answer)
}

