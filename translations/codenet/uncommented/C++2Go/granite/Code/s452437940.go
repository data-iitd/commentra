
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
reader := bufio.NewReader(os.Stdin)

var a, b, x int64
fmt.Fscanf(reader, "%d %d %d\n", &a, &b, &x)

s := (b / x - a / x)
if a%x == 0 {
s++
}
fmt.Println(s)
}


