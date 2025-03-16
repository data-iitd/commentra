
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
    s, _ := reader.ReadString('\n')
    s = strings.Replace(s, "\n", "", -1)
    for j := 0; j < len(s); j++ {
        for i := 0; i < len(s); i++ {
            if i!= j && s[i] == s[j] {
                fmt.Println("no")
                return
            }
        }
    }
    fmt.Println("yes")
}

