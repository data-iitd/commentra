
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var A, B, C, X int
    fmt.Fscanf(reader, "%d\n", &A)
    fmt.Fscanf(reader, "%d\n", &B)
    fmt.Fscanf(reader, "%d\n", &C)
    fmt.Fscanf(reader, "%d\n", &X)
    X = X / 50
    var i, j, k, kosu int
    for i = 0; i <= A; i++ {
        for j = 0; j <= B; j++ {
            for k = 0; k <= C; k++ {
                if X == (10*i)+(2*j)+k {
                    kosu++
                }
            }
        }
    }
    fmt.Println(kosu)
}

