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
    var A, B int
<<<<<<< HEAD
    var ans int
    var out int

    fmt.Scanf("%d %d", &A, &B)
=======
    var ans, out int
    var input string

    input = strings.TrimSpace(string(os.Stdin.Read(1024)))
    input = strings.Split(input, " ")[0]
    A, _ = strconv.Atoi(input)
    input = strings.TrimSpace(string(os.Stdin.Read(1024)))
    input = strings.Split(input, " ")[0]
    B, _ = strconv.Atoi(input)
>>>>>>> 98c87cb78a (data updated)

    out = 1
    for out < B {
        out--
        out += A
        ans++
    }

    fmt.Printf("The answer is: %d\n", ans)
}

