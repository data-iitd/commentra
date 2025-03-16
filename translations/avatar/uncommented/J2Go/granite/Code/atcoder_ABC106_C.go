
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
reader := bufio.NewReader(os.Stdin)

str, _ := reader.ReadString('\n')
str = strings.TrimSpace(str)

k, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadLine()), 10, 64)

n := len(str)

for i := 0; i < int(k); i++ {
if str[i] == '1' {
if i == int(k)-1 {
fmt.Println(1)
return
}
} else {
fmt.Println(str[i])
return
}
}
}

