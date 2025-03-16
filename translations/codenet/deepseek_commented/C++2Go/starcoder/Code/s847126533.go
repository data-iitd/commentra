<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Function to check if it's possible to carry all books with n people and a given weight limit
func check(n int, wei int, book []int) bool {
    tmp := wei
    n--
    for i := 0; i < len(book); i++ {
        if tmp < book[i] {
            if n > 0 {
                n--
                tmp = wei
                if tmp < book[i] {
                    return false
                }
            } else {
                return false
            }
        }
        tmp -= book[i]
    }
    return true
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        line, err := reader.ReadString('\n')
        if err!= nil {
            break
        }
        line = strings.TrimSpace(line)
        if line == "