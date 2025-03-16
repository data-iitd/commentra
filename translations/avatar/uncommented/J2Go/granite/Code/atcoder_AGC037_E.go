
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
scanner := bufio.NewScanner(os.Stdin)
const N = 100000
var K int
var S string
firstTime := true
step := 1
scanner.Scan()
K, _ = strconv.Atoi(scanner.Text())
scanner.Scan()
S = scanner.Text()
for K > 0 {
T := strings.Builder{}
T.WriteString(S)
T.WriteString(reverse(S))
revU := strings.Builder{}
revU.WriteString(T.String())
revU.WriteString(reverse(T.String()))
sDash := S
for i := N; i >= 0; i -= step {
tmp := revU.String()[i : i+N]
if sDash > tmp {
sDash = tmp
} else {
if!firstTime {
break
}
}
}
if firstTime {
firstTime = false
if int(math.Pow(2, float64(K))) > N {
for i := 0; i < N; i++ {
fmt.Print(string(sDash[0]))
}
fmt.Println()
os.Exit(0)
}
} else {
step *= 2
}
K--
S = sDash
}
fmt.Println(reverse(S))
}

func reverse(s string) string {
r := []rune(s)
for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
r[i], r[j] = r[j], r[i]
}
return string(r)
}

