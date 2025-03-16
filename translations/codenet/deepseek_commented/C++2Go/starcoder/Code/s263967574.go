<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter an integer: ")
    input, _ := reader.ReadString('\n')
<<<<<<< HEAD
    input = strings.TrimSpace(input)
    x, _ := strconv.Atoi(input)
=======
    x, _ := strconv.Atoi(strings.TrimSpace(input))
>>>>>>> 98c87cb78a (data updated)
    if x >= 1200 {
        fmt.Println("ARC")
    } else {
        fmt.Println("ABC")
    }
}

