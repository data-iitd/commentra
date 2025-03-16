
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
in := bufio.NewReader(os.Stdin)

s, _ := in.ReadString('\n')
s = strings.TrimSpace(s)

n := len(s)

set := make(map[string]bool)

k, _ := strconv.Atoi(strings.TrimSpace(in.ReadLine()))

res := 0

for i := 0; i < k; i++ {
input, _ := in.ReadString('\n')
input = strings.TrimSpace(input)

a := 0
b := 0

for j := 0; j < n; j++ {
if string(s[j]) == string(input[0]) {
a++
} else if string(s[j]) == string(input[1]) {
b++
} else {
res += int(math.Min(float64(a), float64(b)))
a = 0
b = 0
}
}

res += int(math.Min(float64(a), float64(b)))
}

fmt.Println(res)
}

