
/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    if n <= 0 {
        fmt.Fprintf(writer, "%d\n", 0)
    }
    writer.Flush()
}

