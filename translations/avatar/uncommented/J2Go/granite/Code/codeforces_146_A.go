
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
x, y, t, n int
l            []rune
)

in := bufio.NewReader(os.Stdin)

fmt.Fscanf(in, "%d\n", &n)

str, _ := in.ReadString('\n')

l = []rune(strings.TrimSpace(str))

for i := 0; i < n; i++ {
if l[i]!= '4' && l[i]!= '7' {
t = 1
}
}

if t == 1 {
fmt.Println("NO")
} else {
for i := 0; i < n/2; i++ {
x += int(l[i] - '0')
}

for i := n - 1; i > (n/2)-1; i-- {
y += int(l[i] - '0')
}

if x == y {
fmt.Println("YES")
} else {
fmt.Println("NO")
}
}
}
