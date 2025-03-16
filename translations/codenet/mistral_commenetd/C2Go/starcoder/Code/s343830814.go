<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    var buf [512]byte
    var len int
    fmt.Fscanln(os.Stdin, &buf)
    len = len(strings.TrimSpace(string(buf[:])))
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

