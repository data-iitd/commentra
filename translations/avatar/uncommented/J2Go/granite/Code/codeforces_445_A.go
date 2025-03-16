
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

inp, _ := reader.ReadString('\n')
inp = strings.TrimSpace(inp)

inp_arr := strings.Split(inp, " ")

n, _ := strconv.Atoi(inp_arr[0])
m, _ := strconv.Atoi(inp_arr[1])

ans := make([]string, n)

for i := 0; i < n; i++ {
str, _ := reader.ReadString('\n')
str = strings.TrimSpace(str)

temp := strings.Builder{}

for j := 0; j < m; j++ {
if str[j] == '-' {
temp.WriteString("-")
} else {
if (i+j)%2 == 1 {
temp.WriteString("W")
} else {
temp.WriteString("B")
}
}
}

ans[i] = temp.String()
}

for i := 0; i < n; i++ {
fmt.Println(ans[i])
}
}

