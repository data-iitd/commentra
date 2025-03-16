
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
reader := bufio.NewReader(os.Stdin)

var n, k int
var i, req int = 1, 1

fmt.Fscanf(reader, "%d\n", &n)
fmt.Fscanf(reader, "%d\n", &k)

for k-req >= 0 {
if k-req >= 0 {
k = k - req
} else {
break
}
i++
if i%n!= 0 {
req = i % n
} else {
req = n
}
}
fmt.Println(k)
}

