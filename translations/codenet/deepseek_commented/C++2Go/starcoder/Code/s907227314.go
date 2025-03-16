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
    s = strings.TrimSpace(s)
    a, z := 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            a = i
            break
        }
    }
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' {
            z = i
            break
        }
    }
    fmt.Println(z - a + 1)
}

