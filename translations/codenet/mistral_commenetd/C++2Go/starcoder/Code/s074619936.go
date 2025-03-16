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
    for {
        fmt.Print("Enter a string: ")
        text, _ := reader.ReadString('\n')
<<<<<<< HEAD
        text = strings.TrimSpace(text)
=======
        text = strings.TrimSuffix(text, "\n")
>>>>>>> 98c87cb78a (data updated)
        if text == "0" {
            break
        }
        sum := 0
        for _, c := range text {
            sum += int(c - '0')
        }
        fmt.Println(sum)
    }
}

