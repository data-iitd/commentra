<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var mes string
    fmt.Scanf("%s", &mes)
    fmt.Printf("%c%s%c\n", mes[0], strconv.Itoa(len(mes)-2), mes[len(mes)-1])
}

