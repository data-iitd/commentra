
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

// Main function starts here
func main() {
    reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
=======
    fmt.Print("Enter a string: ")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
>>>>>>> 98c87cb78a (data updated)

    max := 0
    cnt := 0

<<<<<<< HEAD
    for _, sc := range str {
=======
    for _, sc := range input {
>>>>>>> 98c87cb78a (data updated)
        if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
            cnt++
        } else {
            cnt = 0
        }

        if max < cnt {
            max = cnt
        }
    }

    fmt.Println(max)
}

Translate the above Go code to Python and end with comment "