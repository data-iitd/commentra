

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var T, S, q int
    fmt.Fscanf(reader, "%d\n", &T)
    fmt.Fscanf(reader, "%d\n", &S)
    fmt.Fscanf(reader, "%d\n", &q)
    previous := S
    answer := 0
    for previous < T {
        previous *= q
        answer++
    }
    fmt.Println(answer)
}
