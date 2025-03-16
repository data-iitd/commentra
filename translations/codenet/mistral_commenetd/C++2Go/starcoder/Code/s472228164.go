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

func check(x int, y int) string {
    if y%2 == 0 {
        t := (int)(0.5*y) - x

        if t >= 0 && (x-t) >= 0 {
            return "Yes"
        }
    }

    return "No"
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter x and y: ")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSuffix(input, "\n")
    x, _ := strconv.Atoi(strings.Split(input, " ")[0])
    y, _ := strconv.Atoi(strings.Split(input, " ")[1])
    fmt.Println(check(x, y))
}

