
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
var (
str [4]string
i   int
u   int
yes int
)

scanner := bufio.NewScanner(os.Stdin)
for i = -1; i!= 3; i++ {
scanner.Scan()
str[i] = scanner.Text()
}

for u = -1; u!= 2; u++ {
i = -1
for i = -1; i!= 2; i++ {
if (str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) || (str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i])) {
yes = 1
fmt.Println("YES")
break
}
}
if yes == 1 {
break
}
}

if yes == 0 {
fmt.Println("NO")
}
}

