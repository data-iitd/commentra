
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
    fmt.Print("Enter two integers: ")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    a, _ := strconv.Atoi(input[:len(input)-1])
    b, _ := strconv.Atoi(input[len(input)-1:])
    result := 6 - a - b
    fmt.Println(result)
}

