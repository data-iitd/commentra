<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "strings"
)

func main() {
    var mes string
    fmt.Scanf("%s", &mes)

    length := len(mes) - 2
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    fmt.Printf("%c%d%c\n", mes[0], length, mes[len(mes)-1])
}

