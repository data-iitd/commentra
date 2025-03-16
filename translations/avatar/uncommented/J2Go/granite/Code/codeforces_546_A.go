
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
var pandu, vundu, urdu, c int64

reader := bufio.NewReader(os.Stdin)

pandu, _ = strconv.ParseInt(reader.ReadString('\n')[0:len(reader.ReadString('\n')[0])-1], 10, 64)
vundu, _ = strconv.ParseInt(reader.ReadString('\n')[0:len(reader.ReadString('\n')[0])-1], 10, 64)
urdu, _ = strconv.ParseInt(reader.ReadString('\n')[0:len(reader.ReadString('\n')[0])-1], 10, 64)

for i := int64(1); i <= urdu; i++ {
c += i * pandu
}

if c < vundu {
fmt.Println("0")
} else {
fmt.Println(c - vundu)
}
}

