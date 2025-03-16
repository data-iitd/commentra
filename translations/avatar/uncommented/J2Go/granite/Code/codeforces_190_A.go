
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
reader := bufio.NewReader(os.Stdin)

var n, m int
fmt.Fscanf(reader, "%d %d\n", &n, &m)

if n == 0 {
if m!= 0 {
fmt.Println("Impossible")
} else {
fmt.Println("0 0")
}
return
}

if m <= n {
if m == 0 {
m = 1
}
fmt.Printf("%d %d\n", n, m+n-1)
return
}

fmt.Printf("%d %d\n", m, m+n-1)
}

