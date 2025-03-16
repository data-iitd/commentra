
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
    var a int
    var b int
    var result int

    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter first integer: ")
    text, _ := reader.ReadString('\n')
    a, _ = strconv.Atoi(strings.TrimSpace(text))
    fmt.Print("Enter second integer: ")
    text, _ = reader.ReadString('\n')
    b, _ = strconv.Atoi(strings.TrimSpace(text))

    if a > b {
        result = 2 * a - 1
    } else if a == b {
        result = 2 * a
    } else {
        result = 2 * b - 1
    }

    fmt.Println(result)
}

